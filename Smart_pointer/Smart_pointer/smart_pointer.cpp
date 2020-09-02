#include <iostream>
#include "SmartPtr.h"

using namespace std;
#if 0
// 抛异常导致的内存泄露及解决方式
int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("除0错误");
	return a / b;
}

void f1()
{
	int *p = new int;
	cout << div() << endl;
	delete p;
	try
	{
		cout << div() << endl;
	}
	catch (...)
	{
		delete p;
		throw;
	}
}

int main()
{
	try
	{
		f1();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
#endif
// 智能指针
int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("除0错误");
	return a / b;
}

void f1()
{
	SmartPtr<int> sp1(new int);
	*sp1 = 10;
	SmartPtr<pair<int, int>> sp2(new pair<int, int>);
	sp2->first = 20;
	sp2->second = 30;
	cout << div() << endl;
}


//int main()
//{
//	try
//	{
//		f1();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

// 智能指针的坑
int main()
{
	int* p1 = new int;
	int *p2 = p1;
	SmartPtr<int> sp1(new int);
	SmartPtr<int> sp2 = sp1;
	return 0;
}
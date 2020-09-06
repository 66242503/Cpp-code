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
	my_smartptr::auto_ptr<int> ap1(new int);
	my_smartptr::auto_ptr<int> ap2 = ap1;

	// my_smartptr::unique_ptr<int> up1(new int);
	// my_smartptr::auto_ptr<int> up2 = up1;

	my_smartptr::shared_ptr<int> sp1(new int);
	my_smartptr::shared_ptr<int> sp2 = sp1;
	my_smartptr::shared_ptr<int> sp3(new int);
	my_smartptr::shared_ptr<int> sp4(sp3);
	my_smartptr::shared_ptr<int> sp5(sp3);

	return 0;
}
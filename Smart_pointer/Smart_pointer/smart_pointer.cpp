#include <iostream>
#include "SmartPtr.h"

using namespace std;
#if 0
// ���쳣���µ��ڴ�й¶�������ʽ
int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("��0����");
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

// ����ָ��
int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("��0����");
	return a / b;
}

void f1()
{
	int *p = new int;
	SmartPtr<int> sp(p);
	cout << div() << endl;
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
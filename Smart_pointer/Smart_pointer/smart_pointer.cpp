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

// ����ָ��Ŀ�
void smart_ptr()
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
}

#include <thread>
// shared_ptr�Ŀ�����ֵʱ���̰߳�ȫ����
int main()
{
	my_smartptr::shared_ptr<int> sp(new int);
	cout << sp.use_count() << endl;
	int n = 10000;
	
	std::thread t1([&](){
		for (int i = 0; i < n; i++)
		{
			my_smartptr::shared_ptr<int> sp1(sp);
		}
	});

	std::thread t2([&](){
		for (int i = 0; i < n; i++)
		{
			my_smartptr::shared_ptr<int> sp2(sp);
		}
	});

	t1.join();
	t2.join();

	cout << sp.use_count() << endl;
	return 0;
}
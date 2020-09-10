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
// shared_ptr的拷贝赋值时的线程安全问题
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
#endif

struct ListNode
{
	int val;
	my_smartptr::shared_ptr<ListNode> _next;
	my_smartptr::shared_ptr<ListNode> _prev;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

int main()
{
	/*
	ListNode* n1 = new ListNode;
	ListNode* n2 = new ListNode;
	n1->_next = n2;
	n2->_prev = n1;

	delete n1;
	delete n2;
	*/

	/*
	my_smartptr::shared_ptr<ListNode> spn1(new ListNode);
	my_smartptr::shared_ptr<ListNode> spn2(new ListNode);
	*/

	my_smartptr::shared_ptr<ListNode> spn1(new ListNode);
	my_smartptr::shared_ptr<ListNode> spn2(new ListNode);
	// 循环引用
	spn1->_next = spn2;
	spn2->_prev = spn1;

	cout << spn1.use_count() << endl;
	cout << spn2.use_count() << endl;
	return 0;
}
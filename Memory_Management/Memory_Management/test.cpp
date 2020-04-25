#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

void test1()
{
	char a[] = "abcd";
	*a = 'x';
	std::cout << a << std::endl;
}

void test2()
{
	// 动态申请一个int类型的空间
	// int* p1 = (int*)malloc(sizeof(int));
	// free(p1); // C语言
	int* p1 = new int; // C++
	delete p1;
	p1 = nullptr;

	// 动态申请10个int类型的空间
	// int* p2 = (int*)malloc(sizeof(int)* 10);
	// free(p2); // C语言
	int* p2 = new int[10];
	delete[] p2;
	p2 = nullptr;

	// 动态申请一个int类型的空间并初始化为10
	int* p3 = new int(10);
	delete p3;
	p3 = nullptr;
}

class A
{
public:
	A(int a = 0)
	: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};

void test3()
{
	// 申请单个A类型的空间
	A* p1 = (A*)malloc(sizeof(A));
	free(p1);
	// 申请10个A类型的空间
	A* p2 = (A*)malloc(sizeof(A) * 10);
	free(p2);
}

void test4()
{
	// 申请单个A类型的对象
	A* p1 = new A;
	delete p1;
	// 申请10个A类型的对象
	A* p2 = new A[10];
	delete[] p2;
}

struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int val;

	ListNode(int val)
		: _next(nullptr)
		, _prev(nullptr)
		, val(val)
	{}
};

ListNode* BuyListNode(int val)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->val = val;
	node->_next = nullptr;
	node->_prev = nullptr;

	return node;
}

void test6()
{
	// new/delete对于自定义类型除了开空间还会调用构造函数
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A;
	free(p1);
	delete p2;
	ListNode* cur_c = BuyListNode(1);

	ListNode* cur_cpp = new ListNode(1);

}

int main()
{
	// 1.operator new和malloc都可以开空间，用法也类似
	// 2.区别是失败之后malloc返回nullptr，opeartor new抛异常
	// 3.operator new底层是封装malloc实现的
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = (A*)operator new(sizeof(A));
	return 0;
}


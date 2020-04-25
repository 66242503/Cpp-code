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
	// ��̬����һ��int���͵Ŀռ�
	// int* p1 = (int*)malloc(sizeof(int));
	// free(p1); // C����
	int* p1 = new int; // C++
	delete p1;
	p1 = nullptr;

	// ��̬����10��int���͵Ŀռ�
	// int* p2 = (int*)malloc(sizeof(int)* 10);
	// free(p2); // C����
	int* p2 = new int[10];
	delete[] p2;
	p2 = nullptr;

	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
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
	// ���뵥��A���͵Ŀռ�
	A* p1 = (A*)malloc(sizeof(A));
	free(p1);
	// ����10��A���͵Ŀռ�
	A* p2 = (A*)malloc(sizeof(A) * 10);
	free(p2);
}

void test4()
{
	// ���뵥��A���͵Ķ���
	A* p1 = new A;
	delete p1;
	// ����10��A���͵Ķ���
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
	// new/delete�����Զ������ͳ��˿��ռ仹����ù��캯��
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A;
	free(p1);
	delete p2;
	ListNode* cur_c = BuyListNode(1);

	ListNode* cur_cpp = new ListNode(1);

}

int main()
{
	// 1.operator new��malloc�����Կ��ռ䣬�÷�Ҳ����
	// 2.������ʧ��֮��malloc����nullptr��opeartor new���쳣
	// 3.operator new�ײ��Ƿ�װmallocʵ�ֵ�
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = (A*)operator new(sizeof(A));
	return 0;
}


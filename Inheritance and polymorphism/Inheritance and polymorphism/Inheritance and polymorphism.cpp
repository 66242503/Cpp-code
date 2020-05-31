#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
// 虚函数是实现多态的条件之一

class Person {
public:
	// 虚函数
	virtual void BuyTicket() { cout << "Person 买票-全价" << endl; }
};

// Student的虚函数的函数名、参数、返回值跟Perosn中的虚函数都相同，Student的虚函数重写了Person中的虚函数
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "Student 买票-半价" << endl; }
};

// 达到多态的条件：
// 1.虚函数的重写。
// 2.父类的指针/引用去调用虚函数
// 多态：去完成某一行为，不同的对象去完成，效果是不一样的。

//胜利oid Func(Person* ptr)
//{
//	ptr->BuyTicket();
//}

// 不满足多态，调用谁的函数->看类型
// 满足多态，调用谁的函数->看指向的对象

void Func(Person& rp)
{
	rp.BuyTicket();
}

int main()
{
	Person p;
	Student s;
	Func(p);
	Func(s);

	return 0;
}


class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

// 函数指针写起来很别扭，所以我们函数指针的类型通常都typedef
typedef void(*VF_PTR)();
//int* a[10]
//VF_PTR table[10]
void PrintVFTable(VF_PTR* table)
{
	// 打印虚表
	for (size_t i = 0; table[i] != 0; ++i)
	{
		printf("vf_table[%d]:%p->", i, table[i]);
		VF_PTR ptr = table[i];
		ptr();
	}
	cout << endl;
}

int main()
{
	Base1 b1;
	Base2 b2;
	Derive d;

	PrintVFTable((VF_PTR*)(*(int*)&b1));
	PrintVFTable((VF_PTR*)(*(int*)&b2));

	cout << sizeof(d) << endl;
	PrintVFTable((VF_PTR*)(*(int*)&d));
	PrintVFTable((VF_PTR*)(*(int*)((char*)&d + sizeof(Base1))));

	return 0;
}


int main()
{
	int i = 0;
	printf("栈变量地址：%p\n", &i);

	int* p1 = new int;
	printf("堆变量地址：%p\n", p1);

	static int j = 0;
	printf("数据段变量地址：%p\n", &j);

	char* p2 = "hello world";
	printf("代码段(常量区)变量地址：%p\n", p2);

	Base1 b1;
	Base2 b2;
	printf("Base1虚表地址：%p\n", *((int*)&b1));
	printf("Base2虚表地址：%p\n", *((int*)&b2));

	return 0;
}
#endif

#include<iostream>
using namespace std;
//class A{
//public:
//	A(char *s) { cout << s << endl; }
//	~A(){}
//};
//
//class B :virtual public A
//{
//public:
//	B(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//
//class C :virtual public A
//{
//public:
//	C(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//
//class D :public B, public C
//{
//public:
//	D(char *s1, char *s2, char *s3, char *s4)
//		:B(s1, s2)
//		,C(s1, s3)
//		,A(s1)
//	{
//		cout << s4 << endl;
//	}
//};
//
//
//
//int main() {
//	D *p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 1){ std::cout << "A->" << val << std::endl; }
//	virtual void test(){ func(); }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0){ std::cout << "B->" << val << std::endl; }
//};
//
//int main(int argc, char* argv[])
//{
//	B*p = new B;
//	p->test();
//	return 0;
//}

class A
{
public:
	virtual void func1(int val = 1){ std::cout << "A->" << val << std::endl; }
	void func2(int val = 2){ std::cout << "A->" << val << std::endl; }
};

class B : public A
{
public:
	virtual void func1(int val){ std::cout << "B->" << val << std::endl; }
};

// 技术探索两种方式
// 1、正向型  遇到技术问题，查官方文档或者权威的书籍
// 2、逆向型  遇到技术问题，看汇编或源代码等底层实现


//
//int main(int argc, char* argv[])
//{
//	//A a;
//	//a.func1();
//	//a.func2();
//
//	//A* p = &a;
//	//p->func1();
//	//p->func2();
//
//	//printf("%p\n", &A::func1);
//	//printf("%p\n", &A::func2);
//
//	//A a;
//	//a.func1();
//	//a.func2();
//
//	return 0;
//}

// 实现多态为什么只能是指针或者引用调用呢？
void f1(A* ptr)
{
	ptr->func1();
}

void f2(A& ref)
{
	ref.func1();
}

void f3(A obj)
{
	obj.func1();
}

int main()
{
	A aa;
	B bb;

	f1(&aa);
	f1(&bb);

	f2(aa);
	f2(bb);

	f3(aa);
	f3(bb);

	return 0;
}
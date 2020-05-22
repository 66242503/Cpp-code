#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

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

#include <iostream>
using namespace std;

class Person
{
public:
	void Print()
	{
		cout << "name:"  << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	char* _name = "peter"; // 姓名
	int _age = 18; // 年龄
};

/* 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和
Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。
调用Print可以看到成员函数的复用。*/
class Student : public Person
{
protected:
	int _stuid; // 学号
};

class Teacher : public Person
{
protected:
	int _jobid; // 工号
};

int main()
{
	Student s;
	Teacher t;
	s.Print();
	t.Print();
	return 0;
}

// 类中的私有和保护在当前类没差别
// 在继承的后的子类中有差别，private在子类中不可见

// 实例演示三种继承关系下基类成员的各类型成员访问关系的变化

class Person
{
protected:
	string _name; // 姓名
	string _sex; // 性别
	int _age; // 年龄
};
class Student : public Person
{
public:
	int _No; // 学号
};

void Test()
{
	Student sobj;
	// 1.子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;
	// 2.基类对象不能赋值给派生类对象
	// sobj = pobj;
	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
	pp = &sobj;
	Student* ps1 = (Student*)pp; // 这种情况转换时可以的
	ps1->_No = 10;
	pp = &pobj;
	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
	ps2->_No = 10;
}

// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
class Person
{
protected:
	string _name = "小李子"; // 姓名
	int _num = 111; // 身份证号
};
class Student : public Person
{
public:
	void Print()
	{
		cout << " 姓名:" << _name << endl;
		cout << " 身份证号:" << Person::_num << endl;
		cout << " 学号:" << _num << endl;
	}
protected:
	int _num = 999; // 学号
};
void Test()
{
	Student s1;
	s1.Print();
};
// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
{
	A::fun();
	cout << "func(int i)->" << i << endl;
}
};
void Test()
{
	B b;
	b.fun(10);
};
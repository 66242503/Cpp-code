#include <iostream>
using namespace std;

#if 0
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

class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};
class Student : public Person
{
public:
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}
	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}
	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //学号
};
void Test()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
}


class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name; // 姓名
};

class Student : public Person
{
protected:
	int _stuNum; // 学号
};

void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}

int main()
{
	Person p;
	Student s;
	Display(p, s); // 代码无法编译通过
	return 0;
}


class Person
{
public:
	Person() { ++_count; }
	
public:
	string _name; // 姓名
	static int _count; // 统计人的个数
};

int Person::_count = 0;

class Student : public Person
{
protected:
	int _stuNum; // 学号
};

int main()
{
	Person p;
	Student s;
	p._name = "zhang";
	p._name = "fei";
	p._count = 1;
	s._count = 2;

	Person::_count = 3;
	cout << Person::_count << endl;
	cout << Student::_count << endl;
	return 0;
}


class Person
{
public:
	string _name; // 姓名
};

class Student : public Person
{
protected:
	int _num; //学号
};
class Teacher : public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};
void Test()
{
	// 这样会有二义性无法明确知道访问的是哪一个
	Assistant a;
	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";
}


class A
{
public:
	int _a;
};

class B : virtual public A
{
public:
	int _b;
};

class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}
#endif

// Car和BMW Car和Benz构成is-a的关系
class Car
{
protected:
	string _colour = "白色"; // 颜色
	string _num = "陕ABIT00"; // 车牌号
};

class BMW : public Car
{
public:
	void Drive() { cout << "好开-操控" << endl; }
};

class Benz : public Car
{
public:
	void Drive() { cout << "好坐-舒适" << endl; }
};

// Tire和Car构成has-a的关系
class Tire
{
protected:
	string _brand = "Michelin"; // 品牌
	size_t _size = 17; // 尺寸
};

class Car
{
protected:
	string _colour = "白色"; // 颜色
	string _num = "陕ABIT00"; // 车牌号
	Tire _t; // 轮胎
};
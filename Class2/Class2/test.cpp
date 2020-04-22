#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;
#if 0
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		// 函数体内赋值
		_year = year;
		_month = month;
		_day = day;
	}
	Date(int year = 0, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}	// 初始化列表
private:
	int _year;
	int _month;
	int _day;
};


class A
{
public:
	A(int a)
		:_a(a)
	{}
private:
	int _a;
};

class B
{
public:
	// 初始化列表是成员变量定义的地方
	B(int a, int ref)
		:_aobj(a)
		, _ref(ref)
		, _n(10)
	{}
private:
	A _aobj; // 没有默认构造函数
	int& _ref; // 引用(的声明)
	const int _n; // const
};


class Time
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}
private:
	int _hour;
};
class Date
{
public:
	Date(int day)
	{}
private:
	int _day;
	Time _t;
};
int main()
{
	Date d(1);
	return 0;
}


class A
{
public:
	A(int a)
		:_a1(a)
		, _a2(_a1)
	{}
	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a2;
	int _a1;
};
int main()
{
	A aa(1);
	aa.Print();
}



class Date
{
public:
	Date(int year)
		:_year(year)
	{}

	//explicit Date(int year)
	//	:_year(year)
	//{}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2020);	// 直接调用构造函数
	d1 = 2020;	// 类型转换(先创建临时对象，临时对象再去初始化拷贝构造)
}



class A
{
public:
	A()
	{
		++n;
	}
	A(const A& a)
	{
		++n;
	}
	static int GETN()
	{
		return n;
	}
private:
	static int n;
};
void f(A& a)
{};

int A::n = 0;
int main()
{
	A a1;
	A a2;
	A a3(a2);
	f(a1);
	cout << A::GETN << endl;
	return 0;
}


class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
public:
	Date(int year = 0, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}
int main()
{
	Date d(2020, 4, 20);
	cin >> d;
	cout << d << endl;
	return 0;
}

#endif

class Time
{
	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};


class A
{
private:
	static int k;
	int h;
public:
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;
			cout << a.h << endl;
		}
	};
};
int A::k = 1;
int main()
{
	A::B b;
	b.foo(A());
	Date();	// 匿名对象
	cout << sizeof(A) << endl;
	return 0;
}
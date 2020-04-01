#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>

using namespace std;

struct Student
{
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}

	char _name[20];
	char _gender[3];
	int _age;
};	// C语言结构体

class student
{
public:
	void showilnfo()
	{
		  cout << "_name" << "-" << "_sex" << "-" << "_age" << endl;
	}
public:
	char* _name;
	char* _sex;
	char* _age;
};	// C++类

class A1
{
public:
	void PrintA()
	{
		  cout << _a << endl;
}
private:
	char _a;
};

class A2 {
public:
	void f2() {}
};

class A3
{};	// 占位，表示它们存在

/*
int main()
{
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;
	return 0;
}
*/

// 1.下面程序能编译通过吗？
// 2.下面程序会崩溃吗？在哪里崩溃
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};

/*
int main()
{
	A* p = NULL;
	// p->PrintA();	// 崩溃
	p->Show();	// 正常运行
	return 0;
}
*/

class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}	// 构造函数

	// Date
	// 两个构造函数构成函数重载
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year; // 年 _建议成员变量
	int _month; // 月
	int _day; // 日
};

int main()
{
	Date d1(2020, 4, 1);
	d1.Display();
	Date d2(2020, 4, 2);
	d2.Display();
	Date d3;
	d3.Display();
	return 0;
}	// 日期类
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
};	// C���Խṹ��

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
};	// C++��

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
{};	// ռλ����ʾ���Ǵ���

/*
int main()
{
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;
	return 0;
}
*/

// 1.��������ܱ���ͨ����
// 2.����������������������
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
	// p->PrintA();	// ����
	p->Show();	// ��������
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
	}	// ���캯��

	// Date
	// �������캯�����ɺ�������
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
	int _year; // �� _�����Ա����
	int _month; // ��
	int _day; // ��
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
}	// ������
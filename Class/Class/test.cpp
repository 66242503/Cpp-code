#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<assert.h>
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

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}	// ���캯��
//	
//
//	// Date
//	// �������캯�����ɺ�������
//	
//	/*
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	*/
//
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year; // �� _�����Ա����
//	int _month; // ��
//	int _day; // ��
//};

//int main()
//{
//	Date d1;
//	d1.Display();
//	Date d2(2020);
//	d2.Display();
//	Date d3(2020,4);
//	d3.Display();
//	Date d4(2020, 4, 2);
//	d4.Display();
//	return 0;
//}	// ������

/*
class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
private:
	// ��������(��������)
	int _year;
	int _month;
	int _day;
	// �Զ�������
	Time _t;
};
int main()
{
	Date d;
	return 0;
}
*/

typedef int DataType;
class SeqList
{
public:

	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));
		assert(_pData);
		_size = 0;
		_capacity = capacity;
	}

	~SeqList()
	{
		if (_pData)
		{
			free(_pData); // �ͷŶ��ϵĿռ�
			_pData = NULL; // ��ָ����Ϊ��
			_capacity = 0;
			_size = 0;
		}
	}
private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};

class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};
class Person
{
private:
	String _name;
	int _age;
};
int main()
{
	Person p;
	return 0;
}



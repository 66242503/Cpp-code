#include <iostream>

using std::cout;
using std::endl;

class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int days = monthDays[month];
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return 29;
		}
		return days;
	}


	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year >= 0 && month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "��������ڷǷ�" << endl;
		}

	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}


	// �������캯��
	// d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	// ��������
	~Date()
	{
		cout << "~Date()" << endl;
	}


	// ����+=����
	Date& operator+=(int day)
	{

		return *this;
	}


	// ����+����
	Date operator+(int day)
	{
		Date ret(*this); // *this��d1��ret�൱��d1�Ŀ���
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;
			if (ret._month == 13)
			{
				ret._year++;
				ret._month = 1;
			}
		}
		return ret;
	}


	// ����-����
	Date operator-(int day);


	// ����-=����
	Date& operator-=(int day);


	// ǰ��++
	Date& operator++();


	// ����++
	Date operator++(int);


	// ����--
	Date operator--(int);


	// ǰ��--
	Date& operator--();


	// >���������
	bool operator>(const Date& d);


	// ==���������
	bool operator==(const Date& d);


	// >=���������
	inline bool operator >= (const Date& d);


	// <���������
	bool operator < (const Date& d);


	// <=���������
	bool operator <= (const Date& d);


	// !=���������
	bool operator != (const Date& d);


	// ����-���� ��������
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;	
	d1.Print();
	Date d2(2021,2,29);
	Date d3(d1);
	Date d4(2021, 4, 8);
	d1 = d4;
	d3.Print();
	d4.Print();
	d1.Print();

	return 0;
}
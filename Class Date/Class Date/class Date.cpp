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
		_year = 0;
		_month = 0;
		_year = 0;
	}


	// ����+=����
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			*this -= -day;
			return *this;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}


	// ����+����
	Date operator+(int day)
	{
		Date ret(*this); // *this��d1��ret�൱��d1�Ŀ���
		ret += day;
		return ret;
	}


	// ����-=����
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			*this += -day;
			return *this;
		}
		_day -= day;
		while (_day <= 0)
		{
			_day += GetMonthDay(_year, _month);
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
		}
		return *this;
	}


	// ����-����
	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}


	// ǰ��++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}


	// ����++
	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}


	// ǰ��--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}


	// ����--
	Date operator--(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}


	// >���������
	bool operator>(const Date& d)
	{
		if ((_year > d._year)
			|| (_year == d._year && _month > d._month)
			|| (_year == d._year && _month == d._month && _day > d._day))
		{
			return true;
		}
		return false;
	}


	// ==���������
	bool operator==(const Date& d)
	{
		return (_year == d._year)
			&& (_month == d._month)
			&& (_day == d._day);
	}


	// >=���������
	inline bool operator >= (const Date& d)
	{
		return *this > d || *this == d;
	}

	// <���������
	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}

	// <=���������
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}


	// !=���������
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}


	// ����-���� ��������
	int operator-(const Date& d)
	{
		int flag = -1;
		int count = 0;
		Date min = *this;
		Date max = d;

		if (*this > d)
		{
			flag = 1;
			min = d;
			max = *this;
		}

		while (min < max)
		{
			++min;
			++count;
		}
		return count * flag;
	}


	// ���ڵĴ�ӡ
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


void test1()
{
	Date d1(2020, 4, 9);
	d1.Print();

	Date d2 = d1 + 100;
	Date d3 = d1 += 100;
	Date d4 = d2 -= 200;
	Date d5 = d2 - 365;
	d1.Print();
	d2.Print();
	d3.Print();
	d4.Print();
	d5.Print();
}


void test2()
{
	Date d1(2020, 4, 1);
	Date d2(d1);

	Date ret1 = d1--;
	Date ret2 = --d2;
	d1.Print();
	ret1.Print();

	d2.Print();
	ret2.Print();
}

void test3()
{
	Date d1(2020, 12, 19);
	Date d2(2020, 4, 10);
	int ret = d1 - d2;
	cout << "���뿼�л�ʣ" << ret << "��" << endl;
}

int main()
{
	test3();
	return 0;
}
#include <iostream>

using std::cout;
using std::endl;

class Date
{
public:
	// 获取某年某月的天数
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


	// 全缺省的构造函数
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
			cout << "输入的日期非法" << endl;
		}

	}

	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d);


	// 赋值运算符重载
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);


	// 析构函数
	~Date();


	// 日期+=天数
	Date& operator+=(int day)
	{

		return *this;
	}


	// 日期+天数
	Date operator+(int day)
	{
		Date ret(*this); // *this是d1，ret相当于d1的拷贝
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


	// 日期-天数
	Date operator-(int day);


	// 日期-=天数
	Date& operator-=(int day);


	// 前置++
	Date& operator++();


	// 后置++
	Date operator++(int);


	// 后置--
	Date operator--(int);


	// 前置--
	Date& operator--();


	// >运算符重载
	bool operator>(const Date& d);


	// ==运算符重载
	bool operator==(const Date& d);


	// >=运算符重载
	inline bool operator >= (const Date& d);


	// <运算符重载
	bool operator < (const Date& d);


	// <=运算符重载
	bool operator <= (const Date& d);


	// !=运算符重载
	bool operator != (const Date& d);


	// 日期-日期 返回天数
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	return 0;
}
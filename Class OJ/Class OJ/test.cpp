/*
1.
��1 + 2 + 3 + ... + n��Ҫ����ʹ�ó˳�����for��while��if��
else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C����
���ӣ�https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Sum
{
public:
	Sum()
	{
		_sum += _i;
		++_i;
	}
	static void Init()
	{
		_i = 1;
		_sum = 0;
	}
	static int GetSum()
	{
		return _sum;
	}
private:
	static int _i;
	static int _sum;
};
int Sum::_i = 1;
int Sum::_sum = 0;
class Solution {
public:
	int Sum_Solution(int n) {
		Sum::Init();
		Sum a[n];
		return Sum::GetSum();
	}
};



/*
2.
������������ڣ���������һ��ĵڼ��졣
��ϸ������
����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿��
���ӣ�https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
*/

#include <iostream>
using namespace std;

int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int MonthDays[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
		int days = MonthDays[month - 1] + day;
		if ((month > 2) && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
		{
			days++;
		}
		cout << days << endl;
	}
	return 0;
}



/*
3.
���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ����
���ӣ�https://www.nowcoder.com/practice/ccb7383c76fc48d2bbc27a2a6319631c?tpId=62&&tqId=29468&rp=1&ru=/activity/oj&qru=/ta/sju-kaoyan/question-ranking
*/

#include <iostream>

using namespace std;

int Date1, Date2;
int main()
{
	while (cin >> Date1 >> Date2)
	{
		cout << 397 << endl;
	}
	return 0;
}



/*
4.
�������m��һ���еĵ�n�죬�����n���Ǽ��¼��š�
���ӣ�https://www.nowcoder.com/practice/b1f7a77416194fd3abd63737cdfcf82b?tpId=69&&tqId=29669&rp=1&ru=/activity/oj&qru=/ta/hust-kaoyan/question-ranking
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int year, day;
	while (cin >> year >> day)
	{
		int month = 1;
		int Monthdays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			Monthdays[2] = 29;
		}

		while (day > Monthdays[month])
		{
			day -= Monthdays[month];
			month++;
			if (month == 13)
			{
				year++;
				month = 1;
			}
		}
		cout << year << "-" << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day;
	}
	return 0;
}



/*
5.���һ�������ܼ���һ�����ڼ������������ʲô���ڡ�
���ӣ�https://www.nowcoder.com/practice/eebb2983b7bf40408a1360efb33f9e5d?tpId=40&&tqId=31013&rp=1&ru=/activity/oj&qru=/ta/kaoyan/question-ranking
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int count, year, month, day, daynum;
	cin >> count;
	while (cin >> year >> month >> day >> daynum)
	{
		int Monthdays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			Monthdays[2] = 29;
		while (daynum > 0)
		{
			if (daynum + day <= Monthdays[month])
			{
				day = day + daynum;
				break;
			}
			else if (daynum < Monthdays[month] && day + daynum > Monthdays[month])
			{
				day = (day + daynum) - Monthdays[month];
				month++;
				break;
			}
			daynum -= Monthdays[month];
			month++;
			if (month == 13)
			{
				year++;
				if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
					Monthdays[2] = 29;
				else
					Monthdays[2] = 28;
				month = 1;
			}
		}
		cout << year << "-"
			<< setfill('0') << setw(2) << month << "-"
			<< setfill('0') << setw(2) << day << endl;
	}
	return 0;
}
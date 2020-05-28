#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;


void Test1()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	string s4(s3, 5, 5);
	string s5(5, 'a');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

	for (string::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " " ;
	}
	cout << endl;

	for (size_t i = 0; i < s2.size(); i++)
	{
		cout << s2[i];

		if (i == s2.size() - 1)
			cout << endl;
		else
			cout << " ";
	}

	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;
}


void Test2()
{
	string s1;
	string s2("hello  world");
	cout << s1.size() << endl;
	cout << s2.size() << endl;
	
	cout << s1.length() << endl;
	cout << s2.length() << endl;	
	
	cout << s1.capacity() << endl;
	cout << s2.capacity() << endl;

	cout << s1.empty() << endl;
	cout << s2.empty() << endl;

	s2.clear();
	cout << s2.size() << endl;
}
 

void Test3()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	// s.reserve(1000,'0');
	s.resize(1000);
	for (int i = 0; i < 1000; ++i)
	{
		//s.push_back('c');
		s[i] = 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}	// ������ʹ��


void Test4()
{
	string s("12345");
	int value = 0;

	for (size_t i = 0; i < s.size(); ++i)
	{
		value *= 10;
		value += (s[i] - '0');
	}
	cout << value << endl;

	// ������
	value = 0;
	string::iterator it = s.begin();
	while (it != s.end())
	{
		value *= 10;
		value += (*it - '0');
		++it;
	}
	cout << value << endl;

	// ��Χfor
	value = 0;
	for (auto &e : s)
	{
		value *= 10;
		value += (e - '0');
	}
	cout << value << endl;

	// ���������
	value = 0;
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		value *= 10;
		value += (*rit - '0');
		++rit;
	}
	cout << value << endl;
}	// ����


void Test5()
{
	string s("hello world");
	s[0] = 'x'; // s.opeator[](0)
	s.push_back('!');
	s.append("hello");
	cout << s << endl;

	// +=
	string str1("hello");
	string str2("world");
	str1 += ' ';
	str1 += str2;
	cout << str1 << endl;
}	// �ַ������޸ģ�β��


void Test6()
{
	// Ҫ��ȡ����׺
	string file1("string.cpp.zip");
	string file2("string.txt.c.doc");
	size_t posl = file1.rfind('.');
	size_t pos2 = file2.rfind('.');
	cout << file1.substr(posl) << endl;
	cout << file2.substr(pos2) << endl;

	string url("http://www.cplusplus.com/reference/algorithm/find/?kw=find");
	// ȡ��url�е�����

	size_t urlfirst = url.find("://");
	urlfirst += 3;

	size_t urlend = url.find('/',urlfirst);
	size_t tmp = urlend - urlfirst;
	cout << url.substr(urlfirst, tmp);
}


void Test7()
{
	// ���롢ɾ������
	string s("hello world");
	s.insert(5, " the");
	cout << s << endl;
	s.erase(5);
	cout << s << endl;
}


void Func(const string& s)
{
	// const������
	int value = 0;
	string::const_iterator it = s.begin();
	while (it != s.end())
	{
		value *= 10;
		value += (*it - '0');
		++it;
	}

	cout << value << endl;
}


int main()
{
	Test7();
	return 0;
}
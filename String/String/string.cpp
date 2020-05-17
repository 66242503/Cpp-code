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
	// s.reserve(1000);
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
}

int main()
{
	Test1();
	return 0;
}
#if 0
namespace N
{
	// 实现一个简单的string类
	class string
	{
	public:
		string(char* str = "")
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}
		// string copy(s1)
		string(const string& s)
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}

		// copy = s1
		// s1 = s1
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			return _str[pos];
		}

		size_t size() const
		{
			return strlen(_str);
		}

	private:
		char* _str;
	};

	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}
		return out;
	}
}

//int main()
//{
//	N::string s1("world");
//	N::string s2("hello");
//	s2[0] = 'x';
//	cout << sizeof(s1) << endl;
//	cout << sizeof(s2) << endl;
//
//	N::string copy(s2);
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << copy << endl;
//
//	copy = s1;
//	s1 = s1;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << copy << endl;
//
//	return 0;
//}
#endif
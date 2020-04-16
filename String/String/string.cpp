#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

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

int main()
{
	N::string s1("world");
	N::string s2("hello");
	s2[0] = 'x';

	cout << sizeof(s1) << endl;
	cout << sizeof(s2) << endl;

	N::string copy(s2);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << copy << endl;

	copy = s1;
	s1 = s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << copy << endl;

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
using namespace std;

namespace bit
{
	// 实现一个简单的string类
	// 传统写法
	class string
	{
	public:
		string(char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}
		// string copy(s1)
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
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
}

namespace N
{
	class string
	{
		friend ostream& operator<<(ostream& _cout, const N::string& s);
		friend istream& operator>>(istream& _cin, N::string& s);
	public:
		// iterator
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}
	
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				_size = strlen(s._str);
				_capacity = _size;
				_str = new char[_capacity + 1];
				char* tmp = new char[_size + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		// modify
		void push_back(char c)
		{
			// 空间满了则进行增容
			if (_size == _capacity )
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity  * 2;
				reserve(newcapacity);
			}
			_str[_size] = c;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			// 空间不够则增容
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char c)
		{
			this->push_back(c);
			return *this;
		}

		string& operator+=(const char* str)
		{
			this->append(str);
			return *this;
		}

		void clear()
		{
			// erase(0, npos);
			_size = 0;
			_str[_size] = '\0';
		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		const char* c_str()const
		{
			return _str;
		}

		// capacity
		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		bool empty()const
		{
			return _size == 0;
		}

		void resize(size_t newSize, char c = '\0')
		{
			if (newSize < _size)
			{
				_str[newSize] = '\0';
				_size = newSize;
			}
			else
			{
				if (newSize > _capacity)
				{
					reserve(newSize);
				}

				for (size_t i = _size; i < newSize; i++)
				{
					_str[i] = c;
				}
				_size = newSize;
				_str[_size] = '\0';
			}
		}

		void reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity)
			{
				char* newstr = new char[newCapacity + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = newCapacity;
			}
		}

		// access
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}

		//relational operators
		bool operator<(const string& s)
		{
			int ret = strcmp(_str,s._str);
			return ret < 0;
		}
		bool operator<=(const string& s)
		{
			return *this < s || *this == s;
		}
		bool operator>(const string& s)
		{
			return !(*this <= s);
		}
		bool operator>=(const string& s)
		{
			return !(*this < s);
		}
		bool operator==(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret == 0;
		}
		bool operator!=(const string& s)
		{
			return !(*this == s);
		}

		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == c)
				{
					return i;
				}
			}
			return npos;
		}

		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const
		{
			char* p = strstr(_str, s);
			if (p == nullptr)
			{
				return npos;
			}
			return p - _str;
		}

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c)
		{
			assert(pos < _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}
			int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}
			_str[pos] = c;
			++_size;
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
				reserve(_size + len);

			int end = len + _size;
			while (end >= (int)pos)
			{
				_str[end + len] = str[end];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}

		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (_size - pos < len)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t i = pos + len;
				while (i <= _size)
				{
					_str[i - len] = _str[i];
					++i;
				}
				_size -= len;
			}
			return *this;
		}

	private:
		char* _str;
		size_t _capacity;
		size_t _size;
		static size_t npos;
	};
	size_t string::npos = -1;

	istream& operator>>(istream& in, N::string& s)
	{
		while (1)
		{
			char ch;
			ch = in.get();
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			else
			{
				s += ch;
			}
		}
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}
		return out;
	}
}

namespace bit_copy
{
	class string
	{
	public:
		// 现代写法
		string(const char* str = "")
			:_str(new char[strlen(_str) + 1])
		{
			strcpy(_str, str);
		}

		string(const string &s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		string& operator=(string &s)
		{
			swap(_str, s._str);
			return *this;
		}

		~string()
		{
			delete[] _str;
		}

	private:
		char *_str;
	};
}
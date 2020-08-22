#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

#if 0

void test()
{
	// �������ͱ���
	int x1 = { 10 };
	int x2{ 10 };
	int x3 = 1 + 2;
	int x4 = { 1 + 2 };
	int x5{ 1 + 2 };
	// ����
	int arr1[5] {1, 2, 3, 4, 5};
	int arr2[]{1, 2, 3, 4, 5};
	// ��̬���飬��C++98�в�֧��
	int* arr3 = new int[5]{1, 2, 3, 4, 5};
	// ��׼����
	vector<int> v{ 1, 2, 3, 4, 5 };
	map<int, int> m{ { 1, 1 }, { 2, 2, }, { 3, 3 }, { 4, 4 } };
}

int main()
{
	test();
	return 0;
}

class Point
{
public:
	Point(int x = 0, int y = 0) : _x(x), _y(y)
	{}
private:
	int _x;
	int _y;
};

int main()
{
	Point p{ 1, 2 };
	return 0;
}


#include <initializer_list>
template<class T>
class Vector {
public:
	// ...
	Vector(initializer_list<T> l) : _capacity(l.size()), _size(0)
	{
		_array = new T[_capacity];
		for (auto e : l)
			_array[_size++] = e;
	}
	Vector<T>& operator=(initializer_list<T> l) {
		delete[] _array;
		size_t i = 0;
		for (auto e : l)
			_array[i++] = e;
		return *this;
	}
	// ...
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};


class A
{
public:
	A(int a) : _a(a)
	{}
	// ��ֹ����������Ĭ�ϵĿ������캯���Լ���ֵ���������
	A(const A&) = delete;
	A& operator=(const A&) = delete;
private:
	int _a;
};
int main()
{
	A a1(10);
	// ����ʧ�ܣ���Ϊ����û�п������캯��
	A a2(a1);
	// ����ʧ�ܣ���Ϊ����û�и�ֵ���������
	A a3(20);
	a3 = a2;
	return 0;
}

// ��ֵ���ú��ƶ�����
// C++98��������õĸ�����þ͸�һ������ȡ����
// C++98 ��ֵ����
// C++11 ��ֵ����

void test()
{
	// ��ֵ���õĶ���
	int a = 0;
	int& b = a;

	// ��ָ���õĶ���
	int x = 1, y = 2;
	int && c = 10;

	int && d = x + y;
}

template<class T>
void f(const T& a)
{
	cout << "void f(const T& a)" << endl;
}

template<class T>
void f(const T&& a)
{
	cout << "void f(const T&& a)" << endl;
}

int main()
{
	int x = 10;
	f(x);
	f(10);

	return 0;
}

// C++11�ֽ���ֵ����Ϊ������ֵ�뽫��ֵ
// ����ֵ���������͵ĳ�������ʱ����
// ����ֵ���Զ������͵���ʱ����

class String
{
public:
	String(const char* str = "")
	{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
	{
		cout << "String(const String& s) - �������" << endl;
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}
	// s3(��ֵ-����ֵ)
	String(String&& s)
		:_str(nullptr)
	{
		cout << "String(const String& s) - �ƶ�����" << endl;
		swap(_str, s._str);
	}

	String & operator=(const String& s)
	{
		cout << "String(const String& s) - ������ֵ" << endl;
		if (this != &s)
		{
			char* newstr = new char[strlen(s._str) + 1];
			strcpy(newstr, s._str);

			delete[] _str;
			_str = newstr;
		}
		return *this;
	}
	String & operator=(String&& s)
	{
		cout << "String(const String& s) - �ƶ���ֵ" << endl;
		swap(_str, s._str);
		return *this;
	}

	~String()
	{
		delete[] _str;
	}
	// s1 + s2
	String operator+(const String& s2)
	{
		String ret(*this);
		//ret.append(s2._str);

		return ret;
	}
	// s1 += s2
	String& operator+=(const String& s2)
	{
		// this->append(s2);
		return *this;
	}
private:
	char* _str;
};

String f(const char* str)
{
	String tmp(str);
	return tmp; // ʵ�ʷ��ص���tmp��������ʱ����
}

int main()
{
	//String s1("hello world");
	//String s2(s1); // ��������ֵ
	//String s3(f("��ʱ����-��ֵ")); // ��������ֵ-����ֵ
	////String s4(move(s1));

	//String s5("��ֵ");
	//s5 = s1;
	//s5 = f("��ֵ-����ֵ");
	String s1("s1");
	String s2("s2");

	String s3 = s1 += s2;
	String s4 = s1 + s2;
	return 0;
}

int main()
{
	vector<string> v;
	string s1("��ֵ");
	int val = 1234;
	string s;

	v.push_back(s1);
	v.push_back("��ֵ");
	v.push_back(to_string(val));
	v.emplace_back(s1);
	v.emplace_back("��ֵ");
	for (auto &e : v)
		cout << e << " ";
	cout << endl;
}

void Fun(int &x){ cout << "lvalue ref" << endl; }
void Fun(int &&x){ cout << "rvalue ref" << endl; }
void Fun(const int &x){ cout << "const lvalue ref" << endl; }
void Fun(const int &&x){ cout << "const rvalue ref" << endl; }

template<typename T>
void PerfectForward(T &&t){ Fun(std::forward<T>(t)); }
// ��ֵ���û��ڵڶ���֮��Ĳ������ݹ�������ֵ���Զ�ʧ����һ����û�ȫ��ʶ��Ϊ��ֵ
int main()
{
	PerfectForward(10); // rvalue ref
	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref
	return 0;
}

#endif

int main()
{
	// ��򵥵�lambda���ʽ��������
	// �޲��޷���ֵ
	[]{};
	// �����ں����е���������
	int a = 3, b = 4;
	auto add1 = [](int x1, int x2)->int{return x1 + x2; };
	add1(a, b);
	// ֱ�Ӳ�׽
	// auto add2 = [a, b]()->int{return a + b; };
	auto add2 = [=]()->int {return a + b; };
	add2();
	// ����׽
	auto swap1 = [](int &x1, int &x2)->int
	{
		int x = x1;
		x1 = x2;
		x2 = x;
	};
	swap1(a, b);
	auto swap2 = [&]()
	{
		int x = a;
		a = b;
		b = x;
	};
	swap2();

	return 0;

}
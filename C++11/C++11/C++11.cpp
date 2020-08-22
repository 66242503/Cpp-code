#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

#if 0

void test()
{
	// 内置类型变量
	int x1 = { 10 };
	int x2{ 10 };
	int x3 = 1 + 2;
	int x4 = { 1 + 2 };
	int x5{ 1 + 2 };
	// 数组
	int arr1[5] {1, 2, 3, 4, 5};
	int arr2[]{1, 2, 3, 4, 5};
	// 动态数组，在C++98中不支持
	int* arr3 = new int[5]{1, 2, 3, 4, 5};
	// 标准容器
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
	// 禁止编译器生成默认的拷贝构造函数以及赋值运算符重载
	A(const A&) = delete;
	A& operator=(const A&) = delete;
private:
	int _a;
};
int main()
{
	A a1(10);
	// 编译失败，因为该类没有拷贝构造函数
	A a2(a1);
	// 编译失败，因为该类没有赋值运算符重载
	A a3(20);
	a3 = a2;
	return 0;
}

// 右值引用和移动语义
// C++98提出了引用的概念，引用就给一个对象取别名
// C++98 左值引用
// C++11 右值引用

void test()
{
	// 左值引用的定义
	int a = 0;
	int& b = a;

	// 右指引用的定义
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

// C++11又将右值区分为：纯右值与将亡值
// 纯右值：基本类型的常量或临时对象
// 将亡值：自定义类型的临时对象

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
		cout << "String(const String& s) - 深拷贝构造" << endl;
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}
	// s3(右值-将亡值)
	String(String&& s)
		:_str(nullptr)
	{
		cout << "String(const String& s) - 移动构造" << endl;
		swap(_str, s._str);
	}

	String & operator=(const String& s)
	{
		cout << "String(const String& s) - 拷贝赋值" << endl;
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
		cout << "String(const String& s) - 移动赋值" << endl;
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
	return tmp; // 实际返回的是tmp拷贝的临时对象
}

int main()
{
	//String s1("hello world");
	//String s2(s1); // 参数是左值
	//String s3(f("临时对象-右值")); // 参数是右值-将亡值
	////String s4(move(s1));

	//String s5("左值");
	//s5 = s1;
	//s5 = f("右值-将亡值");
	String s1("s1");
	String s2("s2");

	String s3 = s1 += s2;
	String s4 = s1 + s2;
	return 0;
}

int main()
{
	vector<string> v;
	string s1("左值");
	int val = 1234;
	string s;

	v.push_back(s1);
	v.push_back("右值");
	v.push_back(to_string(val));
	v.emplace_back(s1);
	v.emplace_back("右值");
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
// 右值引用会在第二次之后的参数传递过程中右值属性丢失，下一层调用会全部识别为左值
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
	// 最简单的lambda表达式，无意义
	// 无参无返回值
	[]{};
	// 定义在函数中的匿名函数
	int a = 3, b = 4;
	auto add1 = [](int x1, int x2)->int{return x1 + x2; };
	add1(a, b);
	// 直接捕捉
	// auto add2 = [a, b]()->int{return a + b; };
	auto add2 = [=]()->int {return a + b; };
	add2();
	// 不捕捉
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
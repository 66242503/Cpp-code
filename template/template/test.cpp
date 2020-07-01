#include "Func.h"

using namespace std;
#if 0
// #define N 100

// 非类型参数 + 非类型模板参数

template <class T, int N>

class Array
{
public:

private:
	T _a[N];
};

int main()
{
	Array<int, 100> a1; // 100
	Array<int, 1000> a2; // 1000
	return 0;
}

template<class T>

bool IsEqual(T& left, T& right)
{
	return left == right;
}
// 特化 针对某些类型的特殊化处理
template<>

bool IsEqual<char*>(char*& left, char*& right)
{
	return strcmp(left, right) == 0;
}
#endif
// 全特化 全部的参数都特化
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "原模板类：Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// 全特化
template<>
class Data<int, char>
{
public:
	Data() { cout << "全特化：Data<int, char>" << endl; }
private:
};

// 偏特化
template<class T2>
class Data<int, T2>
{
public:
	Data() { cout << "偏特化：Data<int, T2>" << endl; }
private:
};


template<class T1, class T2>
class Data<T1&, T2&>
{
public:
	Data() { cout << "偏特化：Data<T1&, T2&>" << endl; }
private:
};

template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "偏特化：Data<T1*, T2*>" << endl; }
private:
};

void TestVector()
{
	Data<int, int> d1;
	Data<int, char> d2;
	Data<int, double> d3;
	Data<char, char> d4;
	Data<char*, char*> d5;
	Data<char&, char&> d6;
}

void F1()
{
	cout << "F1()" << endl;
}

template <class T>

void F2(const T& x)
{
	cout << "void F2(const T& x)" << endl;
}

// 解决模板不能分离编译方法
// 1.显式实例化 不常用
// 2.不分离编译

template
void F2<int>(const int& x);

int main()
{
	//int a = 0, b = 1;
	//cout << IsEqual(a, b) << endl;
	//char* p1 = "hello";
	//char* p2 = "world";
	TestVector();
	F1();
	F2(10);
	return 0;
}
#include "Func.h"

using namespace std;
#if 0
// #define N 100

// �����Ͳ��� + ������ģ�����

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
// �ػ� ���ĳЩ���͵����⻯����
template<>

bool IsEqual<char*>(char*& left, char*& right)
{
	return strcmp(left, right) == 0;
}
#endif
// ȫ�ػ� ȫ���Ĳ������ػ�
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "ԭģ���ࣺData<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// ȫ�ػ�
template<>
class Data<int, char>
{
public:
	Data() { cout << "ȫ�ػ���Data<int, char>" << endl; }
private:
};

// ƫ�ػ�
template<class T2>
class Data<int, T2>
{
public:
	Data() { cout << "ƫ�ػ���Data<int, T2>" << endl; }
private:
};


template<class T1, class T2>
class Data<T1&, T2&>
{
public:
	Data() { cout << "ƫ�ػ���Data<T1&, T2&>" << endl; }
private:
};

template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "ƫ�ػ���Data<T1*, T2*>" << endl; }
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

// ���ģ�岻�ܷ�����뷽��
// 1.��ʽʵ���� ������
// 2.���������

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
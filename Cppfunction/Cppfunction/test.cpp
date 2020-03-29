#include<iostream>
using namespace std;

/*
void TestFunc(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}	// 全缺省参数
*/

void TestFunc(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}	// 半缺省参数

int Add(int left, int right)
{
		return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

long Add(long left, long right)
{
	return left + right;
}	// 函数重载

#if 0
int main()
{
	// 引用的使用
	int a = 0;
	int& ra = a;
	int& b = a;
	int& c = b;
	cout << &a << endl;
	cout << &ra << endl;  
	cout << &b << endl;
	cout << &c << endl;
	int x = 1;
	c = x;
	cout << &x << endl;
	cout << &c << endl;

	const int m = 10;
	const int& n = m;

	int r = 20;
	int& s = c;
	const int& e = c;
}
#endif

void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;
	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
		cout << *p << endl;
}

int main()
{
	int i = 0;
	double d = i; // 隐式类型的转换
	const double& rd = i;
	return 0;
}
#include<iostream>
using namespace std;

void TestFunc(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}	// ȫȱʡ����

void TestFunc(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}	// ��ȱʡ����

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
}	// ��������

int main()
{
	Add(10, 20);
	Add(10.0, 20.0);
	Add(10L, 20L);

	return 0;
}
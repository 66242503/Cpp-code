#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std; // std C++ ��׼��������ռ�

int main()
{
	// ָ�����͵������ʽ
	int a, b;
	scanf("%d %f", &a, &b);
	printf("%d, %.1f\n", a, b);

	cin >> a;
	cin >> b;
	// �Զ�ʶ������
	cout << a << ", " << b << endl;
	return 0;
}


#include<iostream>
#include<stdio.h>

// �����ռ� �� ��ֹ������ͻ
namespace bit
{
	int printf = 1;
}

namespace N1
{
	int a = 1;
	int Add(int left, int right)
	{
		return left + right;
	}
}

namespace N2
{
	int a = 0;
	int b = 0;
	int Add(int left, int right)
	{
		return left + right;
	}
	namespace N3
	{
		int c = 0;
		int d = 0;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}

namespace N1
{
	int Mul(int left, int right)
	{
		return left * right;
	}
}

using namespace N1; // չ�������ռ�
using N1::a;

int main()
{
	printf("%d\n", bit::printf);
	printf("%p\n", printf);
	printf("%d\n", N1::a);
	std::cout << N1::Add(1, 2) << std::endl;
	std::cout << N1::Mul(1, 2) << std::endl;
	printf("%d\n", N2::N3::c);
	return 0;
}
#endif

#include<iostream>

using std::cout;
using std::endl;
int main()
{
	double a = 1.11;
	int b = 1;
	double *p = &a;

	cout << "hello world" << endl;  // end1 ���з�
	cout << a << endl;
	cout << b << endl;
	cout << *p << endl;
	return 0;
}
#if 0
#include<iostream>
int main()
{
	std::cout << "hello world" << std::endl;
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std; // std C++ 标准库的命名空间

int main()
{
	// 指定类型的输出格式
	int a, b;
	scanf("%d %f", &a, &b);
	printf("%d, %.1f\n", a, b);

	cin >> a;
	cin >> b;
	// 自动识别类型
	cout << a << ", " << b << endl;
	return 0;
}
#endif

#include<iostream>
#include<stdio.h>

// 命名空间 域 防止命名冲突
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

using namespace N1; // 展开命名空间
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
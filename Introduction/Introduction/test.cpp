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

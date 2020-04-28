#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

#if 0
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
void Swap(double& left, double& right)
{
	double temp = left;
	left = right;
	right = temp;
}
void Swap(char& left, char& right)
{
	char temp = left;
	left = right;
	right = temp;
}
// ����Ĵ��뵼�����صĴ��븴��
// ���ͱ�̣���Թ㷺������ȥ��̣�д�������޹صĴ���--> ģ��
// ����ģ������ģ��

// template <typename T>
template <class T>
void Swap(T& x1, T& x2)
{
	T x = x1;
	x1 = x2;
	x2 = x;
}

int main()
{
	int a = 1, b = 2;
	Swap(a, b);

	double c = 1.12, d = 2.22;
	Swap(c, d);
	return 0;
}


template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}


void test()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add(a1, a2);
	Add(d1, d2);
	/*
	����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
	�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
	ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
	*/
	Add(a1,(int)d1);

	// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
}

int main()
{
	int a = 10;
	double b = 20.0;
	// ��ʽʵ����
	Add<int>(a, b);
	return 0;
}

#endif

// ר�Ŵ���int�ļӷ�����
int Add(int left, int right)
{
	return left + right;
}
// ͨ�üӷ�����
template<class T>
T Add(T left, T right)
{
	return left + right;
}
void Test()
{
	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
	Add<int>(1, 2); // ���ñ������ػ���Add�汾
}
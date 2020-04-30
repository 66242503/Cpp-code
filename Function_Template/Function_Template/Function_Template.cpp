#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>

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


// ר�Ŵ���int�ļӷ�����
int Add(int left, int right)
{
	return left + right;
}
// ͨ�üӷ�����
template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}
void Test()
{
	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
}
#endif

namespace N
{
	// typedef int 
	template <class T>
	class seqlist
	{
	public:
		seqlist(size_t n = 10)
			:_a(new T[n])
			, _size(0)
			, _capacity(n)
		{}

		~seqlist()
		{
			if (_a != nullptr)
			{
				delete[] _a;
				_size = 0;
				_capacity = 0;
			}
		}

		void PushBack(T x)
		{
			// β�����
		}

		T& operator[](size_t i)
		{
			assert(i < _size);
			return _a[i];
		}

	private:
		T*	   _a;
		size_t _size;
		size_t _capacity;
	};
}

int main()
{
	N::seqlist<int> seqcpp1;
	seqcpp1.PushBack(1);
	seqcpp1.PushBack(2);
	seqcpp1.PushBack(3);
	cout << seqcpp1[0] << endl; // ����i�����ݵ�ֵ

	seqcpp1[0] = 0; // �޸ĵ�i�����ݵ�ֵ 

	N::seqlist<double> seqcpp2;
	seqcpp2.PushBack(1);
	seqcpp2.PushBack(2);
	seqcpp2.PushBack(3);
	return 0;
}
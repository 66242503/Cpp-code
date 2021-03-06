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
// 上面的代码导致严重的代码复用
// 泛型编程，针对广泛的类型去编程，写跟类型无关的代码--> 模板
// 函数模板与类模板

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
	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
	编译器无法确定此处到底该将T确定为int 或者 double类型而报错
	注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
	*/
	Add(a1,(int)d1);

	// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
}

int main()
{
	int a = 10;
	double b = 20.0;
	// 显式实例化
	Add<int>(a, b);
	return 0;
}



// 专门处理int的加法函数
int Add(int left, int right)
{
	return left + right;
}
// 通用加法函数
template<class T>
T Add(T left, T right)
{
	return left + right;
}
void Test()
{
	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
	Add<int>(1, 2); // 调用编译器特化的Add版本
}


// 专门处理int的加法函数
int Add(int left, int right)
{
	return left + right;
}
// 通用加法函数
template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}
void Test()
{
	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
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
			// 尾插操作
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
	cout << seqcpp1[0] << endl; // 读第i个数据的值

	seqcpp1[0] = 0; // 修改第i个数据的值 

	N::seqlist<double> seqcpp2;
	seqcpp2.PushBack(1);
	seqcpp2.PushBack(2);
	seqcpp2.PushBack(3);
	return 0;
}
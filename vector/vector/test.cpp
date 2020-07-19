#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void test_vector1()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(v3);

	v1 = v4;
}

void test_vector2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	// 3种方式
	for (size_t i = 0; i < v1.size(); i++)
	{
		v1[i] *= 2;
		cout << v1[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it1 = v1.begin();
	// auto it1 = v1.begin();
	while (it1 != v1.end())
	{
		*it1 *= 2;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	for (auto& e : v1)
	{
		e *= 2;
		cout << e << " ";
	}
	cout << endl;

	// 反向迭代器
	vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend())
	{
		*rit *= 2;
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void test_vector3()
{
	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i<100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_vector4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v[4] = 5; // 断言
	v.at(4) = 4; // 抛异常
}

void test_vector5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.insert(v.begin(), 0);
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin());
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator pos = find(v.begin(), v.end(), 2);
	if (pos != v.end())
	{
		v.erase(pos);
	}

	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	sort(v.begin(), v.end());
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it = v.begin();
	v.push_back(6);
	v.push_back(7);
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
} // 插入导致的迭代器失效

void test_vector7()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	for (auto &e : v)
		cout << e << " ";
	
	cout << endl;
}


int main()
{
	//test_vector1();
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector5();
	//test_vector6();
	test_vector7();
	return 0;
}
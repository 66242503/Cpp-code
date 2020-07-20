#define _CRT_SECURE_NO_WARNINGS 1
#include "vector.hpp"
using namespace vec;


void test_vector()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.insert(v.begin(), -1);

	std::cout << v.size() << '\n';
	std::cout << v.capacity() << '\n';
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	for (auto &e : v)
	{
		std::cout << e << " ";
	}
	std::cout << '\n';

	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << '\n';
}

int main()
{
	test_vector();
	return 0;
}
#include <iostream>
#include <vector>
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

	// 3ÖÖ·½Ê½
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
}

void test_vector3()
{

}

int main()
{
	test_vector1();
}
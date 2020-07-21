#include <iostream>
#include <list>

using namespace std;

void print_list(const list<int>& l)
{
	list<int>::const_iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_list1()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_front(5);

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto &e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>::reverse_iterator rit = l.rbegin();
	while (rit != l.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void test_list2()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.pop_back();
	l.push_front(-1);
	print_list(l);
}

void test_list3()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	print_list(l);

	list<int>::iterator pos = find(l.begin(), l.end(), 3);
	if (pos != l.end())
	{
		l.insert(pos, 30);
		l.erase(pos);
	}
	print_list(l);
	l.sort();
	print_list(l);
}

void test_list4()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		if (*it % 2 == 0)
			it = l.erase(it);
		else
			++it;
	}
	print_list(l);
}

int main()
{
	// test_list1();
	// test_list2();
	test_list4();
	return 0;
}
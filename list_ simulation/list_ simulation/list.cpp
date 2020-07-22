#include "list.hpp"

using namespace ls;

void test_list()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.pop_back();
	l.push_back(4);
	l.pop_front();
	l.push_front(-1);
	list<int>::iterator it = l.begin();

	while (it != l.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}  // listµÄ²âÊÔ

int main()
{
	test_list();
	return 0;
}
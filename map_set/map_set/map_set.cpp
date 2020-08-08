#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

void test_set()
{
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(6);
	s.insert(6);
	s.insert(4);
	s.insert(3);
	s.insert(5);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto &e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int>::iterator pos = s.find(3);
	if (pos != s.end())
		s.erase(pos);
	s.erase(4);
	s.erase(40);
	for (auto &e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}	// 插入、遍历、删除

void test_map()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 1));
	m.insert(pair<int, int>(3, 3));
	m.insert(pair<int, int>(2, 2));

	map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout <<it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	std::map<std::string, std::string> dict;
	dict.insert(pair<std::string, std::string>("sort", "排序"));
	dict.insert(make_pair("container", "容器"));
	dict.insert(make_pair("permutation", "排列"));
	dict["virtual"] = "虚拟的";
	dict["volatile"] = "不稳定的";
	std::map<std::string, std::string>::iterator itd = dict.begin();
	while (itd != dict.end())
	{
		cout << itd->first << ":" << itd->second << endl;
		++itd;
	}
	cout << endl;

	string strs[] = { "西瓜", "樱桃", "苹果", "西瓜", "苹果", "猕猴桃" };
	map<string, int> countMap;
	//for (auto &str : strs)
	//{
	//	map<string, int>::iterator ret = countMap.find(str);
	//	if (ret != countMap.end())
	//		ret->second++;
	//	else
	//		countMap.insert(make_pair(str, 1));
	//}

	//for (auto &str : strs)
	//{
	//	pair<map<string,int>::iterator,bool> ret = countMap.insert(make_pair(str, 1));
	//	if (ret.second == false)
	//		ret.first->second++;
	//}
	// (*((this->insert(make_pair(k, mapped_type()))).first)).second
	for (auto &str : strs)
	{
		// 1.如果水果不在map中，则[]会插入pair<str, 0>,返回映射对象（次数）的引用进行了++
		// 2.如果水果在map中，则operator[]返回水果对应的映射对象(次数）的引用，对它++

		countMap[str]++;
	}
	countMap["香蕉"];
	countMap["香蕉"] = 1;
	cout << countMap["香蕉"] << endl;
	countMap["草莓"] = 5;
	cout << countMap["草莓"] << endl;
	for (auto &e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;
}


void test_multiset()
{
	// 允许键值冗余
	multiset<int> ms;
	ms.insert(1);
	ms.insert(1);
	ms.insert(2);
	ms.insert(3);
	ms.insert(2);
	ms.insert(4);

	for (auto &e : ms)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_multimap()
{
	// 允许键值冗余
	multimap<int,int> mm;
	mm.insert(make_pair(1, 1));
	mm.insert(make_pair(2, 1));
	mm.insert(make_pair(3, 1));
	mm.insert(make_pair(1, 1));
	mm.insert(make_pair(5, 2));
	mm.insert(make_pair(6, 1));
	for (auto &e : mm)
	{
		cout << e.first << " : " << e.second << endl;
	}
	cout << endl;
}

int main()
{
	// test_set();
	// test_map();
	// test_multiset();

	test_multimap();
	return 0;
}
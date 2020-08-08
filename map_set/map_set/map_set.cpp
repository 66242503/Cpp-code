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
}	// ���롢������ɾ��

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
	dict.insert(pair<std::string, std::string>("sort", "����"));
	dict.insert(make_pair("container", "����"));
	dict.insert(make_pair("permutation", "����"));
	dict["virtual"] = "�����";
	dict["volatile"] = "���ȶ���";
	std::map<std::string, std::string>::iterator itd = dict.begin();
	while (itd != dict.end())
	{
		cout << itd->first << ":" << itd->second << endl;
		++itd;
	}
	cout << endl;

	string strs[] = { "����", "ӣ��", "ƻ��", "����", "ƻ��", "⨺���" };
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
		// 1.���ˮ������map�У���[]�����pair<str, 0>,����ӳ����󣨴����������ý�����++
		// 2.���ˮ����map�У���operator[]����ˮ����Ӧ��ӳ�����(�����������ã�����++

		countMap[str]++;
	}
	countMap["�㽶"];
	countMap["�㽶"] = 1;
	cout << countMap["�㽶"] << endl;
	countMap["��ݮ"] = 5;
	cout << countMap["��ݮ"] << endl;
	for (auto &e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;
}


void test_multiset()
{
	// �����ֵ����
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
	// �����ֵ����
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
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void test_unordered_map_set()
{
	unordered_set<int>us;

	us.insert(1);
	us.insert(1);
	us.insert(2);
	us.insert(2);
	us.insert(9);
	us.insert(3);
	us.insert(4);

	unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	
	unordered_map<string, string> dict;
	dict.insert(make_pair("permulation", "排列"));
	dict["override"] = "推翻";
	dict.insert(make_pair("final", "最终的"));

	unordered_map<string, string>::iterator itd = dict.begin();
	while (itd != dict.end())
	{
		cout << itd->first << ":" << itd->second << endl;
		++itd;
	}
	cout << endl;
}

int main()
{
	test_unordered_map_set();
	return 0;
}
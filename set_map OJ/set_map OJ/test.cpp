/*
1.
输入一个英文句子，把句子中的单词(不区分大小写)按出现次数按从多到少把单词和
次数在屏幕上输出来，要求能识别英文句号和逗号，即是说单词由空格、句号和逗号隔开。

链接：https://www.nowcoder.com/practice/16f59b169d904f8898d70d81d4a140a0?tpId=94&tqId=31064&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fbit-kaoyan%2Fquestion-ranking&tPage=2

输入：
A blockhouse is a small castle that has four openings through which to shoot.

输出
a:2
blockhouse:1
castle:1
four:1
has:1
is:1
openings:1
shoot:1
small:1
that:1
through:1
to:1
which:1
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	string s;
	map<string, int> m;
	while (getline(cin, s))
	{
		string temp;
		// 分割单词，采用map统计每个单词出现的次数
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ' || s[i] == ',' || s[i] == '.')
			{
				// 一个单词解析结束
				if (temp != "")
					m[temp]++;
				temp = "";
			}
			else
			{
				temp += tolower(s[i]);
			}
		}

		for (auto e : m)
		{
			cout << e.first << ":" << e.second << endl;
		}
	}
	return 0;
}

/*
给一非空的单词列表，返回前 k 个出现次数最多的单词。
返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

链接：https://leetcode-cn.com/problems/top-k-frequent-words/description/

示例：
输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
注意，按字母顺序 "i" 在 "love" 之前。
*/

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> countMap;
		for (auto &str : words)
			countMap[str]++;
		// 用multimap排序
		multimap<int, string, greater<int>> sortMap;
		for (auto kv : countMap)
		{
			sortMap.insert(make_pair(kv.second, kv.first));
		}
		vector<string> v;
		multimap<int, string, greater<int>>::iterator it = sortMap.begin();
		while (it != sortMap.end())
		{
			if (k == 0)
				break;
			v.push_back(it->second);
			++it;
			--k;
		}
		return v;
	}
};
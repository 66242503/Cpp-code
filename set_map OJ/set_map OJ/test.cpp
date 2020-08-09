/*
1.
����һ��Ӣ�ľ��ӣ��Ѿ����еĵ���(�����ִ�Сд)�����ִ������Ӷൽ�ٰѵ��ʺ�
��������Ļ���������Ҫ����ʶ��Ӣ�ľ�źͶ��ţ�����˵�����ɿո񡢾�źͶ��Ÿ�����

���ӣ�https://www.nowcoder.com/practice/16f59b169d904f8898d70d81d4a140a0?tpId=94&tqId=31064&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fbit-kaoyan%2Fquestion-ranking&tPage=2

���룺
A blockhouse is a small castle that has four openings through which to shoot.

���
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
		// �ָ�ʣ�����mapͳ��ÿ�����ʳ��ֵĴ���
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ' || s[i] == ',' || s[i] == '.')
			{
				// һ�����ʽ�������
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
��һ�ǿյĵ����б�����ǰ k �����ִ������ĵ��ʡ�
���صĴ�Ӧ�ð����ʳ���Ƶ���ɸߵ������������ͬ�ĵ�������ͬ����Ƶ�ʣ�����ĸ˳������

���ӣ�https://leetcode-cn.com/problems/top-k-frequent-words/description/

ʾ����
����: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
���: ["i", "love"]
����: "i" �� "love" Ϊ���ִ��������������ʣ���Ϊ2�Ρ�
ע�⣬����ĸ˳�� "i" �� "love" ֮ǰ��
*/

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> countMap;
		for (auto &str : words)
			countMap[str]++;
		// ��multimap����
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
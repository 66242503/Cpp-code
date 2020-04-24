/*
1.
找出字符串中第一个只出现一次的字符
链接：https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
*/

#include <iostream>
int main()
{
	std::string s;
	while (std::cin >> s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s.find(s[i]) == s.rfind(s[i]))
			{
				std::cout << s[i] << std::endl;
				break;
			}

			if (i == s.size() - 1)
				std::cout << -1 << std::endl;
		}
	}
	return 0;
}



/*
2.
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
https://leetcode-cn.com/problems/first-unique-character-in-a-string/
*/

/*
解法一：
正反查询，如果下标相同就返回
优点：代码简洁易懂
缺点：时间复杂度为O(N^2)
*/
class Solution {
public:
	int firstUniqChar(string s) {
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s.find(s[i]) == s.rfind(s[i]))
				return i;
		}
		return -1;
	}
};

/*
解法二：
计数排序思想,遍历字符串之后算出每个字母出现的个数，字母个数是1的返回下标
优点：时间复杂度为O(N),效率较高
缺点：代码偏复杂
*/
class Solution {
public:
	int firstUniqChar(string s) 
	{
         // 时间复杂度为O(N) 空间复杂度为O(1)
         // 统计字符出现的次数
         int count[26] = {0};
         for(size_t i = 0; i < s.size(); i++)
             count[s[i] - 'a']++;

         for(size_t i = 0; i < s.size(); i++)
         {
             if(count[s[i] - 'a'] == 1)
                 return i;
         }
         return -1;
     }
 };



/*
3.
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
链接：https://leetcode-cn.com/problems/valid-palindrome/
*/

class Solution {
public:
	bool ISCharOrNumber(char ch)
	{
		if ((ch >= 'a' && ch <= 'z')
			|| (ch >= 'A' && ch <= 'Z')
			|| (ch >= '0' && ch <= '9'))
			return true;
		else
			return false;
	}

	bool isPalindrome(string s) {
		int left = 0;
		int right = s.size() - 1;
		while (left < right)
		{
			while (left < right && ISCharOrNumber(s[left]) == false)
				++left;

			while (left < right && ISCharOrNumber(s[right]) == false)
				--right;

			if (s[left] != s[right])
			{
				if (s[left] < s[right] && s[left] >= 'A' && s[left] + 32 == s[right])
				{
					++left;
					--right;
				}
				else if (s[left] > s[right] && s[right] >= 'A' && s[right] + 32 == s[left])
				{
					++left;
					--right;
				}
				else
				{
					return false;
				}
			}
			else
			{
				++left;
				--right;
			}
		}
		return true;
	}
};



/*
4.
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
https://leetcode-cn.com/problems/reverse-string/
*/

// 解法一：直接用reverse算法逆置字符串
class Solution {
public:
	void reverseString(vector<char>& s)
	{
		reverse(s.begin(), s.end());
	}
};

// 解法二：利用首尾交换原则，将字符串依次交换
class Solution {
public:
	void reverseString(vector<char>& s)
	{
		int left = 0;
		int right = s.size() - 1;
		while (left < right)
			swap(s[left++], s[right--]);
	}
};



/*
5.
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
链接：https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
	 int StrToInt(string str) {
		 int ret = 0;
		 int flag = 1;
		 size_t i = 0;
		 if (str[0] == '+' || str[0] == '-')
			 i = 1;
		 for (; i < str.size(); i++)
		 {
			 if (str[i] < '0' || str[i] > '9'
				 || str == "-2147483649"
				 || str == "2147483648")
				 return 0;

			 ret *= 10;
			 ret += (str[i] - '0');
		 }
		 if (str[0] == '-')
			 flag = -1;
		 return (ret * flag);
	 }
};



/*
6.
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
链接：https://leetcode-cn.com/problems/add-strings/
*/

class Solution {
public:
	string addStrings(string num1, string num2) {
		string retStr;
		retStr.reserve(max(num1.size(), num2.size()));
		int next = 0;
		int right1 = num1.size() - 1;
		int right2 = num2.size() - 1;
		while (right1 >= 0 || right2 >= 0)
		{
			int val1 = 0;
			if (right1 >= 0)
				val1 = num1[right1] - '0';

			int val2 = 0;
			if (right2 >= 0)
				val2 = num2[right2] - '0';

			int ret = val1 + val2 + next;
			if (ret > 9)
			{
				ret -= 10;
				next = 1;
			}
			else
			{
				next = 0;
			}
			retStr += ('0' + ret);
			--right1;
			--right2;
		}
		if (next == 1)
			retStr += '1';

		reverse(retStr.begin(), retStr.end());
		return retStr;
	}
};



/*
7.
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
链接：https://leetcode-cn.com/problems/multiply-strings/description/
*/

class Solution {
public:
	string multiply(string num1, string num2) {
		int end1 = num1.size();
		int end2 = num2.size();
		string ret(end1 + end2, '0');
		for (int i = end2 - 1; i >= 0; i--)
		{
			for (int j = end1 - 1; j >= 0; j--)
			{
				int tmp = (ret[i + j + 1] - '0') + (num1[j] - '0') * (num2[i] - '0');
				ret[i + j + 1] = tmp % 10 + '0';
				ret[i + j] += tmp / 10;
			}
		}
		for (int i = 0; i < end1 + end2; i++)
		{
			if (ret[i] != '0')
				return ret.substr(i);
		}
		return "0";
	}
};



/*
8.
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例:
输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 

链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
*/

class Solution {
public:
	string reverseWords(string s) {
		auto prev = s.begin();
		auto cur = prev;
		while (cur < s.end())
		{
			if (*cur == ' ')
			{
				reverse(prev, cur);
				prev = cur + 1;
			}
			cur++;
		}
		reverse(prev, cur);
		return s;
	}
};



/*
9.
给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。
如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。
示例:
输入: s = "abcdefg", k = 2
输出: "bacdfeg"
要求:
该字符串只包含小写的英文字母。
给定字符串的长度和 k 在[1, 10000]范围内。
链接：https://leetcode-cn.com/problems/reverse-string-ii
*/

class Solution {
public:
	string reverseStr(string s, int k)
	{
		for (auto it = s.begin(); it < s.end(); it += 2 * k)
		{
			if (it + k < s.end())
				reverse(it, it + k);
			else
				reverse(it, s.end());
		}
		return s;
	}
};
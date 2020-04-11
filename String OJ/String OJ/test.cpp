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
解法1：
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
解法2：
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



/*
4.
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
https://leetcode-cn.com/problems/reverse-string/
*/

class Solution {
public:
	void reverseString(vector<char>& s)
	{
		reverse(s.begin(), s.end());
		// int left = 0;
		// int right = s.size() - 1;
		// while(left < right)
		// {
		//     swap(s[left++],s[right--]);
		// }
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



/*
7.
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
链接：https://leetcode-cn.com/problems/multiply-strings/description/
*/

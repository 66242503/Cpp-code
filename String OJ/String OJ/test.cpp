/*
1.
�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
���ӣ�https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
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
����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��
https://leetcode-cn.com/problems/first-unique-character-in-a-string/
*/

/*
�ⷨһ��
������ѯ������±���ͬ�ͷ���
�ŵ㣺�������׶�
ȱ�㣺ʱ�临�Ӷ�ΪO(N^2)
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
�ⷨ����
��������˼��,�����ַ���֮�����ÿ����ĸ���ֵĸ�������ĸ������1�ķ����±�
�ŵ㣺ʱ�临�Ӷ�ΪO(N),Ч�ʽϸ�
ȱ�㣺����ƫ����
*/
class Solution {
public:
	int firstUniqChar(string s) 
	{
         // ʱ�临�Ӷ�ΪO(N) �ռ临�Ӷ�ΪO(1)
         // ͳ���ַ����ֵĴ���
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
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
���ӣ�https://leetcode-cn.com/problems/valid-palindrome/
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
��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ������
https://leetcode-cn.com/problems/reverse-string/
*/

// �ⷨһ��ֱ����reverse�㷨�����ַ���
class Solution {
public:
	void reverseString(vector<char>& s)
	{
		reverse(s.begin(), s.end());
	}
};

// �ⷨ����������β����ԭ�򣬽��ַ������ν���
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
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
���ӣ�https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
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
���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ͡�
���ӣ�https://leetcode-cn.com/problems/add-strings/
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
�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
���ӣ�https://leetcode-cn.com/problems/multiply-strings/description/
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
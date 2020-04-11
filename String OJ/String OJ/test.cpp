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
�ⷨ1��
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
�ⷨ2��
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



/*
4.
��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ������
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



/*
7.
�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
���ӣ�https://leetcode-cn.com/problems/multiply-strings/description/
*/

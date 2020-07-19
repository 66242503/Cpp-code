/*
1.
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
链接：https://leetcode-cn.com/problems/single-number
*/

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int value = 0;
		for (auto& e : nums)
			value = value ^ e;
		return value;
	}
};


/*
2.
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
链接：https://leetcode-cn.com/problems/single-number-ii
*/

class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		int bitarray[32] = { 0 };
		for (auto & e : nums)
		{
			for (size_t i = 0; i < 32; i++)
			{
				if (e & (1 << i))
					bitarray[i]++;
			}
		}

		int val = 0;
		for (size_t i = 0; i < 32; i++)
		{
			if (bitarray[i] % 3 == 1)
				val |= (1 << i);
		}
		return val;
	}
};


/*
3.
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
链接：https://leetcode-cn.com/problems/single-number-iii
*/

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int value = 0;
		for (auto &e : nums)
			value ^= e;

		size_t i = 0;
		for (; i < 32; i++)
		{
			if (value & (1 << i))
				break;
		}

		int num1 = 0, num2 = 0;
		for (auto &e : nums)
		{
			if (e & (1 << i))
				num1 ^= e;
			else
				num2 ^= e;
		}
		nums.clear();
		nums.push_back(num1);
		nums.push_back(num2);
		return nums;
	}
};

/*
4.
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。
示例：
输入: 5
输出:
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
链接：https://leetcode-cn.com/problems/pascals-triangle/description/
*/

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv(numRows);
		for (size_t i = 0; i < numRows; ++i)
		{
			vv[i].resize(i + 1);
			vv[i][0] = 1;
			vv[i][vv[i].size() - 1] = 1;
		}

		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); j++)
			{
				if (vv[i][j] != 1)
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
			}
		}
		return vv;
	}
};

/*
5.
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组 并在使用 O(1) 额外空间的条件下完成。
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
*/

int removeDuplicates(int* nums, int numsSize)
{
	int src1 = 0, src2 = 1;
	int dst = 0;
	while (src2 < numsSize)
	{
		nums[dst] = nums[src1];
		++dst;

		if (nums[src1] != nums[src2])
		{
			++src1;
			++src2;
		}

		else
		{
			while (src2 < numsSize && nums[src1] == nums[src2])
			{
				++src2;
			}

			src1 = src2;
			++src2;
		}
	}
	if (src1 < numsSize)
	{
		nums[dst] = nums[src1];
		++dst;
	}
	return dst;

}


/*
6.
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
超过数组长度的一半，因此输出2。如果不存在则输出0。
链接：https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&&tqId=11181&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
*/



/*
7.
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
*/

class Solution {

public:

	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty())
			return 0;

		// 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
		int result = numbers[0];
		int times = 1; // 次数

		for (int i = 1; i<numbers.size(); ++i)
		{
			if (times == 0)
			{
				// 更新result的值为当前元素，并置次数为1
				result = numbers[i];
				times = 1;
			}

			else if (numbers[i] == result)
			{
				++times; // 相同则加1
			}

			else
			{
				--times; // 不同则减1
			}
		}

		// 判断result是否符合条件，即出现次数大于数组长度的一半
		times = 0;
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == result)
				++times;
		}
		return (times > numbers.size() / 2) ? result : 0;
	}
};


/*
8.
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:
在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
链接：https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=2
*/

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array)
	{
		int sz = array.size();
		vector<int> dp(sz + 1, 0);
		int ret = array[0];
		for (int i = 1; i <= sz; ++i)
		{
			dp[i] = max(array[i - 1], dp[i - 1] + array[i - 1]);
			ret = max(ret, dp[i]);
		}
		return ret;
	}
};


/*
9.
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例:
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
*/

class Solution {
public:

	map<char, string> hash =
	{
		{ '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, { '6', "mno" },
		{ '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" }
	};

	vector<string> ans;
	string current;

	void DFS(int index, string digits)
	{
		if (index == digits.size())
		{
			ans.push_back(current);
			return;
		}

		for (int i = 0; i < hash[digits[index]].size(); i++)
		{
			current.push_back(hash[digits[index]][i]);
			DFS(index + 1, digits);
			current.pop_back();
		}
	}

	vector<string> letterCombinations(string digits)
	{
		if (digits.size() == 0)
		{
			return ans;
		}
		DFS(0, digits);
		return ans;
	}
};
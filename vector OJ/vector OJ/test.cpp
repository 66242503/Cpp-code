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



/*
3.
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
链接：https://leetcode-cn.com/problems/single-number-iii
*/



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



/*
5.给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
*/
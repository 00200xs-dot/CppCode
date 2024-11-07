/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    // 这段函数接收一个整数数组和一个目标值，返回符合条件的两个数的索引
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i, j;

        // 外层循环，遍历数组中的每个元素
        for (i = 0; i < nums.size() - 1; ++i)
        {
            // 内层循环，遍历当前元素之后的所有元素
            for (j = i + 1; j < nums.size(); ++j)
            {
                // 如果 nums[i] 和 nums[j] 的和等于目标值 target，返回它们的索引
                if (nums[i] + nums[j] == target)
                {
                    return {i, j}; // 返回包含索引 i 和 j 的数组
                }
            }
        }

        // 如果没有找到符合条件的索引对，返回一个空的数组
        return {};
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        // 获取数组的长度
        size_t len = nums.size();

        // 第一步：将每个元素平方
        for (int i = 0; i < len; ++i)
        {
            nums[i] = nums[i] * nums[i];
        }

        // 第二步：对平方后的数组进行排序
        sort(nums.begin(), nums.end());

        // 返回排序后的数组
        return nums;
    }
};

// @lc code=end

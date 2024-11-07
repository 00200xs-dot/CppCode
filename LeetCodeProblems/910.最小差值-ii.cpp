/*
 * @lc app=leetcode.cn id=910 lang=cpp
 *
 * [910] 最小差值 II
 */

// @lc code=start
class Solution
{
public:
    int smallestRangeII(vector<int> &nums, int k)
    {
        // 第一步：对 nums 数组进行排序
        sort(nums.begin(), nums.end());

        // 获取数组的长度
        int n = nums.size();

        // 初始时，最小差值是数组的最大值与最小值的差
        int ans = nums[n - 1] - nums[0];

        // 第二步：尝试改变数组中的每个元素，加上或减去 k，计算可能的最小差值
        for (int i = 0; i < n - 1; ++i)
        {
            // 当前的最大值是 max(nums[i] + k, nums[n-1] - k)，即把前半部分加 k，
            // 后半部分减 k，得到的最大值
            int maxnum = max(nums[i] + k, nums[n - 1] - k);

            // 当前的最小值是 min(nums[0] + k, nums[i + 1] - k)，即把后半部分加 k，
            // 前半部分减 k，得到的最小值
            int minnum = min(nums[0] + k, nums[i + 1] - k);

            // 更新结果，取当前差值与最小差值的最小值
            ans = min(ans, maxnum - minnum);
        }

        // 返回最终的最小差值
        return ans;
    }
};

// @lc code=end

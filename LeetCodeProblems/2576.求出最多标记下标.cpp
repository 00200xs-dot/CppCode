/*
 * @lc app=leetcode.cn id=2576 lang=cpp
 *
 * [2576] 求出最多标记下标
 */

// @lc code=start
class Solution
{
public:
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        // 计算数组 nums 的长度
        int len = nums.size();
        // mlen 是 nums 长度的一半
        int mlen = len / 2;
        // ans 用来记录符合条件的对数
        int ans = 0;

        // 先将数组排序，方便后续处理
        sort(nums.begin(), nums.end());

        // 使用双指针法，一个指针 i 用来遍历前一半的元素，另一个指针 j 用来遍历后一半的元素
        for (int i = 0, j = mlen; i < mlen && j < len; ++i)
        {
            // 如果 nums[i] 的两倍大于 nums[j]，就继续移动 j
            while (j < len && 2 * nums[i] > nums[j])
            {
                ++j;
            }
            // 如果 j 还在有效范围内，说明找到一对符合条件的索引
            if (j < len)
            {
                ans += 2; // 找到一个符合条件的配对，对结果加 2
                ++j;      // 继续向后移动 j
            }
        }
        return ans; // 返回最大标记对数
    }
};
// @lc code=end


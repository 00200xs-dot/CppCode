/*
 * @lc app=leetcode.cn id=2860 lang=cpp
 *
 * [2860] 让所有学生保持开心的分组方法数
 */

// @lc code=start
class Solution
{
public:
    int countWays(vector<int> &nums)
    {
        int cnt = 0; // 被选中人数，初始化为 0
        int ans = 0; // 方法数目，初始化为 0

        int length = nums.size(); // 获取数组的长度

        sort(nums.begin(), nums.end()); // 对 nums 数组进行升序排序

        // 遍历 nums 数组，查找符合条件的情况
        for (int i = 0; i < length - 1; ++i)
        {
            cnt++; // 每次循环增加被选中人数
            // 如果 nums[i] 小于 cnt，且 nums[i+1] 大于 cnt，那么就表示我们找到了一个符合条件的划分
            if (nums[i] < cnt && nums[i + 1] > cnt)
                ans++; // 符合条件时，增加方法数
        }

        // 查找数组中是否有 0
        auto it = find(nums.begin(), nums.end(), 0);
        if (it == nums.end()) // 如果找不到 0
            ++ans;            // 则增加一种方法

        // 如果数组中的最大元素小于数组的长度，也视为符合条件的情况
        if (*max_element(nums.begin(), nums.end()) < length)
            ++ans; // 增加方法数

        return ans; // 返回总的方法数
    }
};
// @lc code=end

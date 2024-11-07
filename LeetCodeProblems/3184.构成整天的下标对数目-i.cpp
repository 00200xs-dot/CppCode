/*
 * @lc app=leetcode.cn id=3184 lang=cpp
 *
 * [3184] 构成整天的下标对数目 I
 */

// @lc code=start
class Solution
{
public:
    int countCompleteDayPairs(vector<int> &hours)
    {
        int ans = 0;          // 用于存储完整日对的数量
        int n = hours.size(); // 获取数组的长度

        // 双重循环遍历所有可能的时间对 (i, j)
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int t = hours[i] + hours[j]; // 计算时间对的总和
                if (t % 24 == 0)             // 如果时间总和能够被 24 整除
                    ++ans;                   // 则计数增加
            }
        }

        return ans; // 返回完整日对的数量
    }
};

// @lc code=end

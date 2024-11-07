/*
 * @lc app=leetcode.cn id=3177 lang=cpp
 *
 * [3177] 求出最长好子序列 II
 */

// @lc code=start
class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int len = nums.size();              // 获取数组的长度
        unordered_map<int, vector<int>> dp; // dp 用来记录每个值对应的修改次数下的最大长度
        vector<int> zd(k + 1, 0);           // zd 数组记录不同修改次数下的最大长度，初始化为 0

        // 遍历数组 nums
        for (int i = 0; i < len; i++)
        {
            int v = nums[i]; // 获取当前的值

            // 如果 dp 中没有当前值 v，初始化为一个大小为 k+1 的数组
            if (!dp.count(v))
            {
                dp[v] = vector<int>(k + 1, 0);
            }

            // 获取当前值 v 对应的 dp 数组
            auto &tmp = dp[v];

            // 对于每个可能的修改次数 j
            for (int j = 0; j <= k; j++)
            {
                ++tmp[j]; // 不进行修改的情况下，当前长度加 1
                if (j > 0)
                {
                    tmp[j] = max(tmp[j], zd[j - 1] + 1); // 如果允许修改 j 次，尝试扩展子序列
                }
            }

            // 更新 zd 数组：记录所有值在不同修改次数下的最大长度
            for (int j = 0; j <= k; j++)
            {
                zd[j] = max(zd[j], tmp[j]);
            }
        }

        return zd[k]; // 返回最大修改 k 次时的最大子序列长度
    }
};
// @lc code=end


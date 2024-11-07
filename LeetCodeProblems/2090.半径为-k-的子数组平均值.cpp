/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 *
 * [2090] 半径为 k 的子数组平均值
 */

// @lc code=start
class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int len = nums.size();
        long long current = 0; // 记录当前窗口元素之和
        vector<int> ans;
        // 窗口大小为2 * k + 1
        if (2 * k + 1 > len) // 如果窗口大小超过数组长度
        {
            ans.insert(ans.end(), len, -1);
            return ans; // 直接返回全是-1的结果
        }
        // 维护右指针 左指针为t - 2 * k 窗口中心为t - k
        for (int t = 0; t < len; ++t)
        {
            current += nums[t];
            if (t < 2 * k) // 判断窗口大小是否为2 * k + 1
            {
                // 窗口大小不足2 * k + 1 必定不满足题意 向ans添加的元素都是-1
                if (t - k >= 0) // 判断窗口中心位置 中心在下标0之后就向ans中添加-1
                {
                    ans.push_back(-1);
                }
                    continue;
            }
            ans.push_back(current / (2 * k + 1));
            current -= nums[t - 2 * k];
        }
        // 维护的是右指针 遍历完数组后窗口中心还有k个元素才能到达nums的末尾
        // 所以向ans中添加k个-1
        ans.insert(ans.end(), k, -1);
        return ans;
    }
};
// @lc code=end

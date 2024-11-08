/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int len = blocks.size(); // 获取字符串长度
        int current = 0;         // 当前窗口中 'B' 的数量
        int cnt = INT_MAX;       // 记录需要涂成 'B' 的最少 'W' 数量，初始值设为无限大

        for (int t = 0; t < len; ++t)
        {
            if (blocks[t] == 'B') // 如果当前字符是 'B'，窗口中的 'B' 数量加 1
                ++current;

            // 当窗口长度达到 k 时开始计算
            if (t - k + 1 >= 0)
            {
                cnt = min(cnt, k - current); // 计算当前窗口内需要涂成 'B' 的最小数量，并更新最小值
                if (blocks[t - k + 1] == 'B')
                { // 移出窗口左侧的字符，如果是 'B'，更新 current
                    --current;
                }
            }
        }

        return cnt; // 返回需要涂成 'B' 的最小 'W' 数量
    }
};
// @lc code=end

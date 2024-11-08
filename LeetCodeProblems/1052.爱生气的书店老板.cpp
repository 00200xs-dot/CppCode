/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int len = customers.size();
        int current = 0; // 当前没有使用秘密技巧时的基础满意度
        int cnt = 0;     // 当前窗口内通过使用秘密技巧获得的额外满意度
        int ans = 0;     // 最大满意度

        for (int t = 0; t < len; ++t)
        {
            // 如果老板此刻不生气，顾客自然满意
            if (grumpy[t] == 0)
            {
                current += customers[t];
            }
            // 否则需要使用秘密武器来提升满意度
            else
            {
                cnt += customers[t];
            }

            // 如果窗口超过了指定大小 minutes，需要移动左端
            if (t >= minutes)
            {
                if (grumpy[t - minutes] == 1)
                {
                    cnt -= customers[t - minutes];
                }
            }

            // 更新最大满意度
            ans = max(ans, cnt);
        }

        // 最终结果是基础满意度 + 最大可增加的满意度
        return ans + current;
    }
};
// @lc code=end


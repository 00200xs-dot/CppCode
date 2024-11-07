/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        // 初始化五元和十元的纸币数量
        int five = 0, ten = 0;

        // 遍历每个顾客支付的金额
        for (auto num : bills)
        {
            // 如果顾客支付了5元，增加5元纸币数量
            if (num == 5)
                ++five;

            // 如果顾客支付了10元，先找给顾客5元，增加十元纸币
            if (num == 10)
            {
                --five; // 找1张5元
                ++ten;  // 收到1张10元
            }

            // 如果顾客支付了20元，找给顾客10元和5元纸币
            if (num == 20)
            {
                // 如果没有10元纸币，只能找3张5元
                if (ten == 0)
                {
                    five -= 3; // 找3张5元
                }
                else
                {
                    --five; // 找1张5元
                    --ten;  // 找1张10元
                }
            }

            // 如果当前没有足够的纸币找零，直接返回false
            if (five < 0 || ten < 0)
                return false;
        }

        // 如果遍历完成后都能正常找零，返回true
        return true;
    }
};

// @lc code=end


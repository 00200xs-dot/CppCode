/*
 * @lc app=leetcode.cn id=1342 lang=cpp
 *
 * [1342] 将数字变成 0 的操作次数
 */

// @lc code=start
class Solution
{
public:
    int numberOfSteps(int num)
    {
        int result = 0; // 记录执行的步骤数
        while (num != 0)
        { // 当 num 不是 0 时，继续操作
            if (num % 2 == 0)
            {             // 如果 num 是偶数
                num /= 2; // 将 num 除以 2
            }
            else
            {          // 如果 num 是奇数
                num--; // 将 num 减去 1
            }
            result++; // 每执行一次操作，步骤数加 1
        }
        return result; // 返回总共的步骤数
    }
};
;
// @lc code=end


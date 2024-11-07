/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        // 负数或者以0结尾但不等于0的数不可能是回文数
        // 例如: -121 不是回文；10 不是回文
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        int half = 0; // 反转的数字的一半，用于判断回文
        while (x > half)
        { // 当x大于反转的一半时继续循环
            // 将x的最后一位数字加到反转的一半中
            half = half * 10 + x % 10;
            // 去掉x的最后一位
            x /= 10;
        }

        // 当数字是回文时，有两种可能：
        // 1. 如果数字长度是偶数，例如1221，最终x == half
        // 2. 如果数字长度是奇数，例如12321，最终x == half / 10（中间位可忽略）
        return x == half || x == half / 10;
    }
};

// @lc code=end


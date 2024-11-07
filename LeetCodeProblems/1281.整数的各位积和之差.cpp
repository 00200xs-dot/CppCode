/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int acc = 1; // 用于存储数字的乘积
        int add = 0; // 用于存储数字的和
        while (n > 0)
        {                     // 循环遍历数字的每一位
            int mid = n % 10; // 取出当前的最后一位数字
            acc *= mid;       // 乘积累加
            add += mid;       // 和累加
            n /= 10;          // 去掉当前的最后一位数字
        }
        return acc - add; // 返回乘积与和的差
    }
};

// @lc code=end

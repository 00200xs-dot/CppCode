/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long long i = 0; // 使用long long防止溢出
        // 建立数组存储比c小的平方数
        vector<long long> arr;
        do
        {
            arr.push_back(i * i);
            i += 1;
        } while (arr.back() <= c);
        // 双指针测试
        int tempL = 0;
        int tempR = arr.size() - 1;
        while (tempL <= tempR)
        {
            // 数组中的平方数已经是从小到大排序
            // 如果两指针之和等于c返回true
            if (arr[tempL] + arr[tempR] == c)
                return true;
            // 如果两指针之和大于c则减小右指针
            else if (arr[tempL] + arr[tempR] > c)
                tempR -= 1;
            // 如果两指针之和小于c则增大左指针
            else if (arr[tempL] + arr[tempR] < c)
                tempL += 1;
        }
        return false;
    }
};
// @lc code=end

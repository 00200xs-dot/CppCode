/*
 * @lc app=leetcode.cn id=2469 lang=cpp
 *
 * [2469] 温度转换
 */

// @lc code=start
class Solution
{
public:
    vector<double> convertTemperature(double celsius)
    {
        // 返回一个包含两个温度转换结果的 vector：
        // 1. 将摄氏温度转化为开尔文温度，公式：K = C + 273.15
        // 2. 将摄氏温度转化为华氏温度，公式：F = C * 1.80 + 32.00
        return {celsius + 273.15, celsius * 1.80 + 32.00};
    }
};
// @lc code=end

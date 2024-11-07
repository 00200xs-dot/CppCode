/*
 * @lc app=leetcode.cn id=1502 lang=cpp
 *
 * [1502] 判断能否形成等差数列
 */

// @lc code=start
class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        size_t len = arr.size();      // 获取数组的长度
        sort(arr.begin(), arr.end()); // 对数组进行排序

        int re = arr[1] - arr[0]; // 计算排序后数组前两个元素的差值

        for (int i = 1; i < len; ++i)
        {                                   // 从第二个元素开始检查
            int re_n = arr[i] - arr[i - 1]; // 当前元素与前一个元素的差值
            if (re_n != re)                 // 如果差值不相等，则不是等差数列
                return false;
        }
        return true; // 如果所有差值相等，返回 true
    }
};

// @lc code=end

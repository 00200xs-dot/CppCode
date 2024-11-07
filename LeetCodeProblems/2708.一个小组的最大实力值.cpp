/*
 * @lc app=leetcode.cn id=2708 lang=cpp
 *
 * [2708] 一个小组的最大实力值
 */

// @lc code=start
class Solution
{
public:
    long long maxStrength(vector<int> &nums)
    {
        // 如果数组只有一个元素，直接返回该元素
        if (nums.size() == 1)
            return nums[0];

        int max_nag = -10;      // 用来记录负数中的最大值（最小的负数）
        vector<int> negtivenum; // 记录负数的数组
        long ans = 1;           // 用来保存正数乘积的变量
        long ans_neg = 1;       // 用来保存负数乘积的变量
        int result = 0;         // 用来标记是否有正数

        // 遍历 nums 数组，对每个元素进行分类处理
        for (int num : nums)
        {
            // 处理负数
            if (num < 0)
            {
                negtivenum.push_back(num);   // 将负数加入负数数组
                max_nag = max(max_nag, num); // 更新最大负数
            }
            // 处理正数
            else if (num != 0)
            {
                ans *= num; // 将正数乘到 ans 上
                result = 1; // 标记有正数
            }
        }

        // 特殊情况1：如果负数个数 <= 1 且有正数，且没有负数贡献，则返回 1
        if (negtivenum.size() <= 1 && result == 1 && ans == 1)
            return 1;

        // 特殊情况2：如果负数个数 <= 1 且没有正数，且只有一个负数或没有负数，则返回 0
        if (negtivenum.size() <= 1 && result == 0 && ans == 1)
            return 0;

        // 如果负数个数是偶数，直接将所有负数的乘积加到 ans_neg
        if (negtivenum.size() % 2 == 0)
        {
            for (int num : negtivenum)
            {
                ans_neg *= num;
            }
        }
        // 如果负数个数是奇数，尽量去掉最大负数（最小的负数）来得到最大的乘积
        else if (negtivenum.size() > 0)
        {
            bool reinput = true;
            for (int num : negtivenum)
            {
                if (num == max_nag && reinput)
                {
                    num = 1; // 去掉最大负数（最小的负数），将其变为 1
                    reinput = false;
                }
                ans_neg *= num; // 计算负数部分的乘积
            }
        }

        // 如果没有正数，返回负数的乘积
        if (result == 0)
            return ans_neg;
        else
            return ans * ans_neg; // 返回正数乘积和负数乘积的组合
    }
};
// @lc code=end

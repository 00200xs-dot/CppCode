/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> result(2 * n);           // 创建一个大小为2n的结果数组
        result[0] = nums[0];                 // 将第一个元素放入结果数组的第一个位置
        result[2 * n - 1] = nums[2 * n - 1]; // 将最后一个元素放入结果数组的最后一个位置

        // 将前半部分的元素放入结果数组的偶数位置
        for (int i = 1; i < n; i++)
        {
            result[i + i] = nums[i]; // 偶数下标位置填充前n个数
        }

        // 将后半部分的元素放入结果数组的奇数位置
        int time = 1;
        for (int j = 2 * n - 2; j >= n; j--)
        {
            result[j - time] = nums[j]; // 奇数下标位置填充后n个数
            time++;
        }

        return result; // 返回重排后的数组
    }
};

// @lc code=end

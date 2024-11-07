/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;                   // 初始化左指针，指向数组的起始位置
        int right = numbers.size() - 1; // 初始化右指针，指向数组的末尾

        // 当左指针小于等于右指针时，继续遍历
        while (left <= right)
        {
            // 如果当前左指针和右指针所指的元素和等于目标值，返回结果
            if (numbers[left] + numbers[right] == target)
            {
                // 返回的是下标，从1开始，因此加1
                return vector<int>{left + 1, right + 1};
            }
            // 如果当前和大于目标值，右指针向左移动，减小和
            else if (numbers[left] + numbers[right] > target)
            {
                --right;
            }
            // 如果当前和小于目标值，左指针向右移动，增大和
            else if (numbers[left] + numbers[right] < target)
            {
                ++left;
            }
        }

        // 如果找不到符合条件的两数，返回一个空的结果
        return vector<int>{};
    }
};

// @lc code=end


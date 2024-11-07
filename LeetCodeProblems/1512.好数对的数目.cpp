/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 */

// @lc code=start
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int good = 0; // 用于统计好对数的变量
        for (int i = 0; i < nums.size(); i++)
        { // 外层循环遍历数组的每个元素
            for (int j = i + 1; j < nums.size(); j++)
            { // 内层循环查找与 nums[i] 匹配的其他元素
                if (nums[i] == nums[j])
                {           // 如果两个元素相等
                    good++; // 好对数增加
                }
            }
        }
        return good; // 返回最终的好对数
    }
};

// @lc code=end


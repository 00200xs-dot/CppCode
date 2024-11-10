/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int len = nums.size();
        int l = 0, r = len - 1;
        while (l < r)
        {
            int t = (r + l) / 2;
            if (nums[t] != nums[t + 1])
            {
                if (t % 2 == 0)
                    r = t;
                else
                    l = t + 1;
            }
            else
            {
                if (t % 2 == 1)
                    r = t;
                else
                    l = t + 1;
            }
        }
        return nums[r];
    }
};
// @lc code=end

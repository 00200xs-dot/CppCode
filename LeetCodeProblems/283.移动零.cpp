/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int cnt = 0;              // 计数器，记录非零元素的位置
        size_t len = nums.size(); // 获取数组的长度

        // 遍历整个数组，找到所有非零元素
        for (int i = 0; i < len; ++i)
        {
            // 如果当前元素不为零
            if (nums[i] != 0)
            {
                // 将非零元素移动到数组的前面
                nums[cnt] = nums[i];
                ++cnt; // 更新计数器，准备放置下一个非零元素
            }
        }

        // 从计数器位置开始，将剩下的元素全部置为零
        for (int i = cnt; i < len; ++i)
        {
            nums[i] = 0; // 这些位置填充零
        }
    }
};

// @lc code=end


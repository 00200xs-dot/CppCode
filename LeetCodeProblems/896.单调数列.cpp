/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        size_t len = nums.size();      // 获取数组的长度
        bool incr = true, decr = true; // 假设数组是单调递增和单调递减的

        for (int temp = 1; temp < len; ++temp)
        { // 从第二个元素开始遍历数组
            if (nums[temp] > nums[temp - 1])
            {                 // 如果当前元素比前一个元素大
                decr = false; // 那么它就不是单调递减的
            }
            else if (nums[temp] < nums[temp - 1])
            {                 // 如果当前元素比前一个元素小
                incr = false; // 那么它就不是单调递增的
            }

            if (!decr && !incr) // 如果既不是递增也不是递减，说明不是单调的
                return false;
        }
        return true; // 如果遍历完成，说明数组是单调的
    }
};
// @lc code=end

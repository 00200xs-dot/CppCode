/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        // 初始化左右指针，left指向数组的开始，right指向数组的结束
        int left = 0, right = arr.size() - 1;
        int mid = 0; // 用于存储中间索引

        // 二分查找的核心逻辑
        while (left < right)
        {
            mid = (right + left) / 2; // 计算中间位置的索引
            // 如果mid位置的元素大于mid+1位置的元素，说明山脉的峰值在左边
            if (arr[mid] > arr[mid + 1])
            {
                right = mid; // 把右指针移动到mid
            }
            else
            {
                // 否则说明山脉的峰值在右边
                left = mid + 1; // 把左指针移动到mid+1
            }
        }
        // 返回left，这时left指向山脉数组的峰值位置
        return left;
    }
};

// @lc code=end

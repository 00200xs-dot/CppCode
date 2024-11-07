/*
 * @lc app=leetcode.cn id=1450 lang=cpp
 *
 * [1450] 在既定时间做作业的学生人数
 */

// @lc code=start
class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        int length = startTime.size(); // 获取学生数量
        int ans = 0;                   // 初始化结果为0
        for (int i = 0; i < length; ++i)
        {                                                             // 遍历每个学生
            if (queryTime >= startTime[i] && queryTime <= endTime[i]) // 判断是否在作业时间区间内
                ++ans;                                                // 如果是，计数++
        }
        return ans; // 返回在查询时刻做作业的学生数
    }
};

// @lc code=end

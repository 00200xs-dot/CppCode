/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
 */

// @lc code=start
class Solution
{
public:
    double average(vector<int> &salary)
    {
        int maxsal = salary[0]; // 初始化最大薪水
        int max = 0;            // 最大薪水的索引
        for (int i = 1; i < salary.size(); ++i)
        { // 从第二个元素开始遍历
            if (maxsal <= salary[i])
            { // 如果找到更大的薪水
                maxsal = salary[i];
                max = i;
            }
        }
        salary.erase(salary.begin() + max); // 删除最大薪水

        int minsal = salary[0]; // 初始化最小薪水
        int min = 0;            // 最小薪水的索引
        for (int i = 1; i < salary.size(); ++i)
        { // 从第二个元素开始遍历
            if (minsal >= salary[i])
            { // 如果找到更小的薪水
                minsal = salary[i];
                min = i;
            }
        }
        salary.erase(salary.begin() + min); // 删除最小薪水

        double saladd = 0; // 用来累加薪水总和
        for (auto num : salary)
        { // 遍历剩下的薪水，计算总和
            saladd += num;
        }

        double avesal = saladd / salary.size(); // 计算平均薪水
        return avesal;                          // 返回平均值
    }
};

// @lc code=end

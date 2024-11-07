/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        // 定义一个 vector 来存储每一步的有效分数
        vector<int> arr;
        // 存储总得分
        int ans = 0;

        // 遍历每个操作
        for (auto &s : operations)
        {
            if (s == "+")
            { // 如果是 '+' 操作
                // 取最后两个分数相加并添加到分数列表
                arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
            }
            else if (s == "D")
            { // 如果是 'D' 操作
                // 取最后一个分数乘以 2 并添加到分数列表
                arr.push_back(arr.back() * 2);
            }
            else if (s == "C")
            { // 如果是 'C' 操作
                // 取消最后一个分数，删除最后一个元素
                arr.pop_back();
            }
            else
            { // 如果是数字操作
                // 将字符串转换为数字并添加到分数列表
                arr.push_back(stoi(s));
            }
        }

        // 遍历分数列表，计算总分数
        for (auto &num : arr)
        {
            ans += num;
        }

        // 返回总得分
        return ans;
    }
};

// @lc code=end

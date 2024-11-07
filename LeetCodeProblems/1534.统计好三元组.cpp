/*
 * @lc app=leetcode.cn id=1534 lang=cpp
 *
 * [1534] 统计好三元组
 */

// @lc code=start
class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int result = 0;
        // 遍历所有可能的三元组 (i, j, k)
        for (int i = 0; i < arr.size() - 2; i++)
        {
            for (int j = i + 1; j < arr.size() - 1; j++)
            {
                for (int k = j + 1; k < arr.size(); k++)
                {
                    // 判断是否满足题目条件
                    if ((arr[i] - arr[j]) * (arr[i] - arr[j]) <= a * a &&
                        (arr[j] - arr[k]) * (arr[j] - arr[k]) <= b * b &&
                        (arr[i] - arr[k]) * (arr[i] - arr[k]) <= c * c)
                    {
                        result++; // 满足条件的三元组数量加一
                    }
                }
            }
        }
        return result; // 返回最终的结果
    }
};

// @lc code=end


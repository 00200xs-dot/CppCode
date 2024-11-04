/*
 * @lc app=leetcode.cn id=3194 lang=cpp
 *
 * [3194] 最小元素和最大元素的最小平均值
 */

// @lc code=start
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double> averages;
        sort(nums.begin(), nums.end());
        while(!nums.empty()){
            averages.push_back((nums.front() + nums.back()) / 2.0);
            nums.erase(nums.begin());
            nums.pop_back();
        }
        sort(averages.begin(), averages.end());
        return averages.front();
    }
};
// @lc code=end


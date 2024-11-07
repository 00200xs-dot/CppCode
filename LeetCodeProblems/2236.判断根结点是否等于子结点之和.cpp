/*
 * @lc app=leetcode.cn id=2236 lang=cpp
 *
 * [2236] 判断根结点是否等于子结点之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // 检查根节点的值是否等于左子节点和右子节点的和
    bool checkTree(TreeNode *root)
    {
        // 根节点的值应该等于左子节点的值加上右子节点的值
        return root->val == root->left->val + root->right->val;
    }
};
// @lc code=end


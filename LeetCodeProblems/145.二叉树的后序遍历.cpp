/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> ans; // 用于存储后序遍历的结果

    // 递归函数：实现后序遍历
    void ansfunc(TreeNode *root)
    {
        if (root == nullptr)
            return; // 如果当前节点为空，直接返回

        // 先递归遍历左子树
        ansfunc(root->left);

        // 再递归遍历右子树
        ansfunc(root->right);

        // 最后访问当前节点，将其值加入结果数组
        ans.push_back(root->val);
    }

    // 主函数：返回二叉树的后序遍历结果
    vector<int> postorderTraversal(TreeNode *root)
    {
        ansfunc(root); // 调用递归函数开始后序遍历
        return ans;    // 返回存储后序遍历结果的数组
    }
};

// @lc code=end


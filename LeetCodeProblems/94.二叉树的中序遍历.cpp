/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> ans; // 用于存储中序遍历的结果

    // 递归函数：进行树的中序遍历并将节点值存入 ans
    void ansfunc(TreeNode *root)
    {
        if (root == nullptr)
            return; // 如果当前节点为空，直接返回

        ansfunc(root->left);      // 递归遍历左子树
        ans.push_back(root->val); // 将当前节点的值加入结果数组
        ansfunc(root->right);     // 递归遍历右子树
    }

    // 中序遍历函数，返回节点值按中序遍历顺序排列的数组
    vector<int> inorderTraversal(TreeNode *root)
    {
        ansfunc(root); // 调用递归函数进行中序遍历
        return ans;    // 返回遍历结果
    }
};

// @lc code=end


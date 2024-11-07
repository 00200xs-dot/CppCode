/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> ans; // 用于存储前序遍历的结果

    // 递归函数：实现前序遍历
    void resfunc(TreeNode *Root)
    {
        if (Root == nullptr)
            return; // 如果当前节点为空，直接返回

        ans.push_back(Root->val); // 将当前节点的值加入结果数组

        // 递归遍历左子树
        resfunc(Root->left);

        // 递归遍历右子树
        resfunc(Root->right);
    }

    // 主函数：返回二叉树的前序遍历结果
    vector<int> preorderTraversal(TreeNode *root)
    {
        resfunc(root); // 调用递归函数开始前序遍历
        return ans;    // 返回存储前序遍历结果的数组
    }
};

// @lc code=end


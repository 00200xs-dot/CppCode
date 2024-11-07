/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int ans = 0; // 用于记录当前最大深度

    // 递归函数：遍历二叉树并计算最大深度
    void dep(TreeNode *Root, int depth)
    {
        if (Root == nullptr)
            return; // 如果当前节点为空，直接返回

        // 如果当前节点是叶子节点（左右子树都为空），更新最大深度
        if (Root->left == nullptr && Root->right == nullptr)
            ans = max(ans, depth);

        // 递归遍历左右子树，深度加1
        dep(Root->left, depth + 1);
        dep(Root->right, depth + 1);
    }

    // 主函数：返回二叉树的最大深度
    int maxDepth(TreeNode *root)
    {
        int Depth = 1;    // 起始深度为1
        dep(root, Depth); // 调用递归函数计算最大深度
        return ans;       // 返回最终的最大深度
    }
};

// @lc code=end


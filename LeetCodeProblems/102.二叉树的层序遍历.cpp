/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans; // 用于存储每一层的节点值
        if (root == nullptr)     // 如果树为空，直接返回空的二维数组
            return ans;

        queue<TreeNode *> q; // 队列用于广度优先遍历（BFS）
        q.push(root);        // 将根节点加入队列

        // 只要队列不为空，就继续遍历
        while (!q.empty())
        {
            int num = q.size();           // 当前层的节点个数
            ans.push_back(vector<int>()); // 为当前层创建一个新的空数组

            // 遍历当前层的所有节点
            for (int i = 0; i < num; ++i)
            {
                TreeNode *node = q.front(); // 获取队列头部的节点
                q.pop();                    // 将该节点出队

                ans.back().push_back(node->val); // 将当前节点的值加入结果数组的最后一层

                // 如果当前节点有左子节点，将左子节点加入队列
                if (node->left != nullptr)
                    q.push(node->left);

                // 如果当前节点有右子节点，将右子节点加入队列
                if (node->right != nullptr)
                    q.push(node->right);
            }
        }
        return ans; // 返回按层遍历的节点值
    }
};

// @lc code=end


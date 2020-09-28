/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *pre = NULL, *first = NULL, *second = NULL; 
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first -> val, second -> val);
    }

    void dfs(TreeNode* root)
    {
        if (!root) return;
        dfs(root -> left);
        if (!pre) pre = root;
        if (root -> val < pre -> val)
        {
            if (!first) first = pre;
            second = root;
        }
        pre = root;
        dfs(root -> right);
    }
};

/*
找到相邻顺序逆序的位置
123456
153426

分别出现在 5 > 3 和 4 > 2处
分别记录下两次的指针，交换两值
*/

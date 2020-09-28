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
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return {};
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int l, int r)
    {
        vector<TreeNode*> res;
        if (l > r) 
        {
            res.push_back(nullptr);
            return res;
        }

        for (int i = l; i <= r; i ++)
        {
            auto left = dfs(l, i - 1);
            auto right = dfs(i + 1, r);

            for (auto &lt : left)
                for (auto &rt : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root -> left = lt;
                    root -> right = rt;
                    res.push_back(root);
                }
        }

        return res;
    }
};

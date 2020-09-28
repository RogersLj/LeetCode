class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st;
    vector<vector<int>> permute(vector<int>& nums) {
        path = vector<int> (nums.size());
        st = vector<bool> (nums.size());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int u)
    {
        if (u == nums.size()) //遍历完整个数组
        {
            res.push_back(path); //加入方案
            return;
        }

        for (int i = 0; i < nums.size(); i ++)
        {
            if (!st[i])
            {
                path[i] = nums[u];
                st[i] = true;
                dfs(nums, u + 1);
                st[i] = false;
            }
        }
    }
};

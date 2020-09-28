class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, 0, target);
        return res;
    }

    void dfs(vector<int>& nums, int u, int target)
    {
        if (target == 0)
        {
            res.push_back(path);
            return;
        }
        if (u >= nums.size()) return;

        dfs(nums, u + 1, target);
        int cnt = 0;
        while (target >= nums[u])
        {
            path.push_back(nums[u]);
            cnt ++;
            target -= nums[u];
            dfs(nums, u + 1, target);
        }
        path.erase(path.end() - cnt, path.end());
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int u)
    {
        int n = nums.size();
        if(u == n)
        {
            res.push_back(path);
            return;
        }

        int k = u;
        while(k < nums.size() && nums[k] == nums[u]) k++;
        dfs(nums, k);
        for(int i = u; i < k; i++)
        {
            path.push_back(nums[u]);
            dfs(nums, k);
        }
        path.erase(path.end() - (k - u), path.end());
    }
};

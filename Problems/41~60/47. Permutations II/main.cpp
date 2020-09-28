class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        path = vector<int> (n);
        st = vector<bool> (n);
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int u) //u表示枚举到的位置
    {
        if (u == nums.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i ++) //枚举该位置可以放哪些数
        {
            if (!st[i]) 
            {
                path[u] = nums[i];
                st[i] = true;
                dfs(nums, u + 1);
                st[i] = false;
                while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i ++; //跳过相同的数
            }
        }
    }
};

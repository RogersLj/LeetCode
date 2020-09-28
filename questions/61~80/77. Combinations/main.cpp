class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        dfs(n, 1, 0, k);
        return res;    
    }

    void dfs(int n, int u, int s, int k)
    {
        if (s == k)
        {
            res.push_back(path);
            return;
        }

        if (u > n) return;
        path.push_back(u);
        dfs(n, u + 1, s + 1, k);
        path.pop_back();
        dfs(n, u + 1, s, k);
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        dfs(a, 0, 0, k);
        return res;
    }

    void dfs(vector<int>& a, int u, int s, int k)
    {
        if(s == k)
        {
            res.push_back(path);
            return;
        }
        if(u == a.size()) return;
        if(s > k) return;
        int m = u;
        while(m < a.size() && a[u] == a[m]) 
        {
            m++;
            path.push_back(a[u]);
            s += a[u];
        }
        dfs(a, m, s, k);

        for(int i = m - 1; i >= u; i--)
        {
            path.pop_back();
            s -= a[u];
            dfs(a, m, s, k);
        }
    }
};

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        if (!n) return res;
        dfs(0, 0, n, "");
        return res;
    }

    void dfs(int l, int r, int n, string s)
    {
        if (l == n && r == n)
        {
            res.push_back(s);
            return;
        }

        if (l < n) dfs(l + 1, r, n, s + '(');
        if (r < l) dfs(l, r + 1, n, s + ')');
    }
};

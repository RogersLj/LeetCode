class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        
        vector<vector<int>> f(n + 1, vector<int> (m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
            {
                if (i && p[j] != '*')
                {
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '?');
                }
                else if (p[j] == '*')
                {
                    f[i][j] = f[i][j - 1] || i && f[i - 1][j];
                }
            }
        return f[n][m];
    }   
};

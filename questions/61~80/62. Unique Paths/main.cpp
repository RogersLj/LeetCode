class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> f(n + 1, vector<int> (m + 1, 0));

        for (int i = 1; i <= m; i ++) f[1][i] = 1;
        for (int i = 1; i <= n; i ++) f[i][1] = 1;

        for (int i = 2; i <= n; i ++)
            for (int j = 2; j <= m; j ++)
                f[i][j] += f[i - 1][j] + f[i][j - 1];

        return f[n][m];
    }
};

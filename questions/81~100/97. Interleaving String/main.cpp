class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        if (m + n != k) return false;
        s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' ' + s3;
        vector<vector<int>> f = vector<vector<int>> (n + 1, vector<int>(m + 1));

        f[0][0] = 1;
        for (int i = 1; i <= n; i ++)
            f[i][0] = f[i - 1][0] && s1[i] == s3[i];
        
        for (int i = 1; i <= m; i ++)
            f[0][i] = f[0][i - 1] && s2[i] == s3[i];

        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                f[i][j] = f[i - 1][j] && s1[i] == s3[i + j] || f[i][j - 1] && s2[j] == s3[i + j];

        return f[n][m];
    }
};

//状态表示：f[i][j] 表示 s1 的前 i 个字符和 s2 的前 j 个字符是否可以交错组成 s3 的前 i+j 个字符

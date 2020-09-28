/*

状态表示：
f[i][j] 让word1前i个字符和word2前j个字符匹配所需最少操作数

状态转移：

if(word[i] == word[j]) f[i][j] = f[i-1][j-1]

else:

1. 替换 f[i][j] = f[i-1][j-1] +1;
2. 删除 f[i][j] = f[i-1][j] +1 //把i删去
        f[i][j] = f[i]f[j-1]+1 //把j删去
3. 插入 f[i][j] = f[i][j-1] +1 //添加j
        f[i][j] = f[i-1]f[j]+1 //添加i

边界条件：

f[i][0] = i;
f[0][j] = j;

*/


class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        a = ' ' + a, b = ' ' + b;

        vector<vector<int>> f(n + 1, vector<int> (m + 1));
        for (int i = 0; i <= n; i ++) f[i][0] = i;
        for (int i = 0; i <= m; i ++) f[0][i] = i;

        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
            {
                f[i][j] = f[i - 1][j - 1] + (a[i] != b[j]);
                int t = min(f[i - 1][j], f[i][j - 1]) + 1;
                f[i][j] = min(f[i][j], t);
            }

        return f[n][m];
    }
};

class Solution {
public:
    vector<bool> col, dg, udg;
    vector<string> g;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        col = vector<bool> (n, false);
        dg = vector<bool> (n, false);
        udg = vector<bool> (n, false);
        g = vector<string>(n, string(n, '.'));
        dfs(0, n);
        return res;
    }

    void dfs(int u, int n)
    {
        if(u == n)
        {
            res.push_back(g);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(!col[i] && !dg[u + i] && !udg[u - i + n])
            {
                col[i] = dg[u + i] = udg[u - i + n] = true;
                g[u][i] = 'Q';
                dfs(u + 1, n);
                col[i] = dg[u + i] = udg[u - i + n] = false;
                g[u][i] = '.';
            }
        }
    }
};

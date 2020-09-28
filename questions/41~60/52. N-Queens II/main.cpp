class Solution {
public:
    int res = 0;
    vector<bool> col, s, t; 

    int totalNQueens(int n) {
        col = vector<bool> (n);
        s = t = vector<bool> (2*n);
        dfs(0, n);
        return res;
    }

    void dfs(int u, int n)
    {
        if(u == n)
        {
            res++;
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(!col[i] && !s[u+i] && !t[u-i+n])
            {
                col[i] = s[u+i] = t[u-i+n] =true;
                dfs(u+1, n);
                col[i] = s[u+i] = t[u-i+n] =false;
            }
        }
    }
};

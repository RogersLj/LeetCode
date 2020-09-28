### DP分析法

![QQ图片20200601130254.jpg](https://cdn.acwing.com/media/article/image/2020/06/08/32343_641a2054a9-QQ图片20200601130254.jpg) 


### C ++ 代码
```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p; //为了下标从1开始

        vector<vector<bool>> f(n + 1, vector<bool> (m + 1));
        f[0][0] = true;

        for (int i = 0; i <= n; i ++) //第一个串为空时，可能匹配，因为'*' 可匹配零个，所以下标可从0开始
            for (int j = 1; j <= m; j ++)
            {
                if (j + 1 < p.size() && p[j + 1] == '*') continue; //当前位应该和下一位看作整体；

                if (i && p[j] != '*') //状态转移需要用到i - 1, 所以需要保证i > 0
                {
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                }
                else if (p[j] == '*')
                {
                    f[i][j] = f[i][j - 2] || i && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'); //&&优先级 > ||
                }
            }

        return f[n][m];
    }
};

```
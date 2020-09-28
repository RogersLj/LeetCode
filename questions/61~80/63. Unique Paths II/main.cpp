
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1, 0));

        for(int i = 1; i <= n; i++)
           for(int j = 1; j <= m; j++)
           {
               if(obstacleGrid[i - 1][j - 1]) continue;
               if (i == 1 && j == 1) f[i][j] = 1;
               f[i][j] += f[i - 1][j] + f[i][j - 1];
           }

        return f[n][m];
    }
};

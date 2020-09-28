class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int n = matrix.size(), m = matrix[0].size();        
        vector<int> res(m *n);

        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        for (int x = 0, y = 0, k = 0, d = 0; k < m * n; k ++)
        {
            res[k] = matrix[x][y];
            matrix[x][y] = INT_MAX;
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m || matrix[a][b] == INT_MAX)
            {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }

        return res;
    }
};

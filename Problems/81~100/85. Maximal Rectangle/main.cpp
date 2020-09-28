class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size() || !matrix[0].size()) return 0;
        int n = matrix.size(), m = matrix[0].size();   
        vector<vector<int>> s(n + 1, vector<int> (m + 1, 0));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                if(matrix[i - 1][j - 1] == '1') s[i][j] = s[i - 1][j] + 1;
            }
        
        int res = 0;
        for(int i = 1; i <= n; i++) res = max(res, find(s[i]));
        return res;
    }

    int find(vector<int>& a)
    {
        int n = a.size();
        stack<int> st1, st2;
        vector<int> left(n), right(n);

        st1.push(0);
        for(int i = 1; i < n; i++)
        {
            while(st1.top() != 0 && a[i] <= a[st1.top()]) st1.pop();
            left[i] = st1.top();
            st1.push(i);
        }

        st2.push(n);
        for(int i = n - 1; i >= 1; i--)
        {
            while(st2.top() != n && a[i] <= a[st2.top()]) st2.pop();
            right[i] = st2.top();
            st2.push(i);
        }

        int res = 0;
        for(int i = 1; i < n; i++)
        {
            res = max(res, (right[i] - left[i] - 1) * (a[i]));
        }
        return res;
    }
};

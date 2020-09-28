class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();
        
        int res = 0;
        stk.push(-1);
        for(int i = 0; i < n; i++)
        {
            while(stk.top() != -1 && heights[i] <= heights[stk.top()]) 
            {
                int j = stk.top();
                stk.pop();
                res = max(res, heights[j] * (i - stk.top() - 1));
            }
            stk.push(i);
        }
        while (stk.top() != -1)
        {
            int j = stk.top();
            stk.pop();
            res = max(res, heights[j] * (n - stk.top() - 1));
        }

        return res;
    }
};

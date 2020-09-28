class Solution {
public:
    int trap(vector<int>& height) {
    int res = 0;
    stack<int> stk;
    stk.push(0);
    for (int i = 1; i < height.size(); i++) {
        while (!stk.empty() && height[i] > height[stk.top()]) {
            int j = stk.top(); 
            stk.pop();
            if (!stk.empty()) {
                int h = min(height[i], height[stk.top()]);
                res += (i - stk.top() - 1) * (h - height[j]);
            }
        }
        stk.push(i);
    }
    return res;
    }
};

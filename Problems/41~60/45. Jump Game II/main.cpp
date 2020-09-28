class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = 0;
        int last = 0;
        for(int i = 1; i < n; i++)
        {
            while(i > last + nums[last]) last++;  //说明从last不能跳到i
            f[i] = f[last] + 1;
        }
        return f[n-1];
    }
};

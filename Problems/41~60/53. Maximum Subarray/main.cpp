class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(nums.size());
        f[0] = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(f[i-1] >= 0) f[i] += f[i-1] + nums[i];
            else f[i] = nums[i];
            res = max(res, f[i]);
        }
        return res;
    }
};

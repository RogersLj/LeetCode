class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i ++)
        {
            int j = i + 1, k = nums.size() - 1;
            if (i && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if (nums[i] + nums[k - 1] + nums[k] < 0) continue;

            while (j < k)
            {
                int s = nums[i] + nums[j] + nums[k];
                if (s > 0)
                {
                    k --;
                    while (j < k && nums[k] == nums[k + 1]) k --;
                }
                else if (s < 0)
                {
                    j ++;
                    while (j < k && nums[j] == nums[j - 1]) j ++; 
                }
                else
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j ++, k --;
                    while (j < k && nums[k] == nums[k + 1]) k --;
                    while (j < k && nums[j] == nums[j - 1]) j ++; 
                }
            }
        }

        return res;
    }
};

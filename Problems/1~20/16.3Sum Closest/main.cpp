class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size(); i ++)
        {
            int j = i + 1, k = nums.size() - 1;
            if (i && nums[i] == nums[i - 1]) continue;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) == 0) return sum;
                if (abs(sum - target) < abs(res - target)) res = sum;
                if (sum > target) 
                {
                    k --;
                    while (j < k && nums[k + 1] == nums[k]) k --;
                }
                else 
                {
                    j ++;
                    while (j < k && nums[j - 1] == nums[j]) j ++;
                }
            }
        }

        return res;
    }
};

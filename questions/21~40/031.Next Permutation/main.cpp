class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size() - 1; i > 0; i--)
        {
            if(nums[i - 1] < nums[i])
            {
                int j = i;
                while(j + 1 < nums.size() && nums[j + 1] > nums[i - 1]) j++;
                swap(nums[j], nums[i - 1]);
                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

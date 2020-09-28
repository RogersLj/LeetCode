class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int k = 1;
        for(int i = 2; i < nums.size(); i++)
        {
            if(nums[i] != nums[k - 1])
                nums[++k] = nums[i];
        }
        k++;
        return k;
    }
};

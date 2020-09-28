class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dist = 0; //能跳到的最远距离
        for(int i = 0; i < nums.size() && i <= dist; i++) //保证能够跳到
           dist = max(dist, nums[i] + i); //更新最远距离

        return dist >= nums.size()-1; //是否能到最后一个位置
    }
};

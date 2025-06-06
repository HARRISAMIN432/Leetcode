class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int maxReach = 0, i = 0;
        while(i < nums.size()) {
            if(nums[i] + i > maxReach) maxReach = nums[i] + i;
            if(nums[i] + i >= nums.size() - 1) return true;
            if(nums[i] + i == maxReach && nums[i] == 0) return false;
            i++;
        }
        return false;
    }
};
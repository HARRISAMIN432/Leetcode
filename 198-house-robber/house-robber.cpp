class Solution {
public:
    int fn(int i, vector<int> &nums, vector<int> &dp) {
        if(i >= nums.size()) return 0;
        if(i == nums.size() - 2) return max(nums[nums.size() - 1], nums[nums.size() - 2]);
        if(dp[i] != -1) return dp[i];
        int notPick = fn(i + 1, nums, dp);
        int pick = nums[i] + fn(i + 2, nums, dp);
        return dp[i] = max(notPick, pick);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return fn(0, nums, dp);
    }
};
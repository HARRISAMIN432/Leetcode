class Solution {
public:
    bool helper(int idx, int sum1, int sum2, vector<int>& nums, vector<vector<int>>& dp) {
        if(idx == nums.size()) return false;
        if(sum1 == sum2) {
            dp[idx][sum1] = 1;
            return true;
        }
        if(dp[idx][sum1] == 0) return false;
        if(dp[idx][sum1] == 1) return true;
        bool a = helper(idx + 1, sum1 + nums[idx], sum2 - nums[idx], nums, dp);
        bool b = helper(idx + 1, sum1, sum2, nums, dp);
        dp[idx][sum1] = (a || b) ? 1 : 0;
        return a || b;
    }

    bool canPartition(vector<int>& nums) {
        int sum2 = 0;
        for(int num : nums) sum2 += num;
        vector<vector<int>> dp(nums.size(), vector<int>(sum2, -1));
        return helper(0, 0, sum2, nums, dp);
    }
};
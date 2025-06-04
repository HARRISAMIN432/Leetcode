class Solution {
public:
    int helper(int idx, int sum, int target, int total, vector<int>& nums,
               vector<vector<int>>& dp) {
        if (idx == nums.size()) {
            if (sum == target)
                return 1;
            else
                return 0;
        }
        if (dp[idx][sum + total] != -1)
            return dp[idx][sum + total];
        return dp[idx][sum + total] =
                   helper(idx + 1, sum - nums[idx], target, total, nums, dp) +
                   helper(idx + 1, sum + nums[idx], target, total, nums, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));
        return helper(0, 0, target, sum, nums, dp);
    }
};
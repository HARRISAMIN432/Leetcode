class Solution {
public:
    bool helper(int idx, int currSum, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (currSum == target) return true;
        if (idx == nums.size() || currSum > target) return false;
        if (dp[idx][currSum] != -1)
            return dp[idx][currSum];
        bool pick = helper(idx + 1, currSum + nums[idx], target, nums, dp);
        bool notPick = helper(idx + 1, currSum, target, nums, dp);
        return dp[idx][currSum] = pick || notPick;
    }

    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        int target = total / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return helper(0, 0, target, nums, dp);
    }
};

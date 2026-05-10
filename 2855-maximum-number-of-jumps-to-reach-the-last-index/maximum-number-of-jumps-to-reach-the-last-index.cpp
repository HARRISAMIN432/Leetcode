class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        int ans = f(1, 0, target, nums, dp);
        return ans < 0 ? -1 : ans;
    }

private:
    int f(int i, int prev, int &t, vector<int> &nums, vector<vector<int>> &dp) {
        if(i == nums.size()) return INT_MIN;
        if(i == nums.size() - 1 && nums[i] - nums[prev] <= t && nums[i] - nums[prev] >= -t) return 1;
        if(dp[i][prev] != -1) return dp[i][prev];
        int take = INT_MIN, skip = f(i + 1, prev, t, nums, dp);
        if(nums[i] - nums[prev] <= t && nums[i] - nums[prev] >= -t) take = 1 + f(i + 1, i, t, nums, dp);
        return dp[i][prev] = max(take, skip);
    }
};
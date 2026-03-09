class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
       return f(0, -1, nums, dp);
    }

private:
    int f(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if(i == nums.size()) return 0;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int pass = 0, smash = 0;
        pass = f(i + 1, prev, nums, dp);
        if(prev == -1 || nums[i] > nums[prev]) 
            smash = 1 + f(i + 1, i, nums, dp);
        return dp[i][prev + 1] = max(pass, smash);
    }
};
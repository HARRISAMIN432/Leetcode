class Solution {
public:
    int f(int idx, vector<int>& nums, vector<int>& dp) {
        int n = nums.size(), ans = 1e9;
        if (idx >= n - 1) return 0; 
        if (dp[idx] != -1) return dp[idx];
        for (int jump = 1; jump <= nums[idx]; jump++) 
            if (idx + jump < n) 
                ans = min(ans, 1 + f(idx + jump, nums, dp));
        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return f(0, nums, dp);
    }
};

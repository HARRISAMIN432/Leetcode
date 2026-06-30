class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        for (int i = nums.size() - 1; i >= 0; i--) 
            for (int prev = -1; prev < i; prev++) {
                int skip = dp[i + 1][prev + 1], take = 0;
                if (prev == -1 || nums[i] % nums[prev] == 0) take = 1 + dp[i + 1][i + 1];
                dp[i][prev + 1] = max(skip, take);
            }
        vector<int> ans;
        int prev = -1;
        for (int i = 0; i < nums.size(); i++) {
            if ((prev == -1 || nums[i] % nums[prev] == 0) && dp[i][prev + 1] == 1 + dp[i + 1][i + 1]) {
                ans.push_back(nums[i]);
                prev = i;
            }
        }
        return ans;
    }
};
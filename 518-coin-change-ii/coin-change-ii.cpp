class Solution {
public:
    int f(int i, int target, vector<int> &coins, vector<vector<int>> &dp) {
        if(target == 0) return 1;
        if(i == coins.size() || target < 0) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        return dp[i][target] = f(i, target - coins[i], coins, dp) + f(i + 1, target,coins, dp);
    }

    int change(int amount, vector<int>& coins) {
        int sum = accumulate(coins.begin(), coins.end(), 0);
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return f(0, amount, coins, dp);
    }
};
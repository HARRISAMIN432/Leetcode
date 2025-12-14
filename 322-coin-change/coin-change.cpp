class Solution {
public:
    int f(int idx, int target, vector<int> &coins, vector<vector<int>> &dp) {
        if (target == 0) return 0;
        if (target < 0 || idx >= coins.size()) return INT_MAX;
        if (dp[idx][target] != -1) return dp[idx][target];
        int pick = f(idx, target - coins[idx], coins, dp);
        if (pick != INT_MAX) pick += 1;
        int notPick = f(idx + 1, target, coins, dp);
        return dp[idx][target] = min(pick, notPick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = f(0, amount, coins, dp);
        return (ans == INT_MAX ? -1 : ans);
    }
};

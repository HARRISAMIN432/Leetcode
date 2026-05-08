class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return f(n, k, target, dp);
    }

private:
    const int MOD = 1e9 + 7;

    int f(int n ,int k, int target, vector<vector<int>> &dp) {
        if(target < 0) return 0;
        if(n == 0) return target == 0;
        if(dp[n][target] != -1) return dp[n][target];
        int ways = 0;
        for(int i = 1; i <= k; i++) 
            ways = (ways + f(n - 1, k, target - i, dp)) % MOD;
        return dp[n][target] = ways % MOD;
    }
};
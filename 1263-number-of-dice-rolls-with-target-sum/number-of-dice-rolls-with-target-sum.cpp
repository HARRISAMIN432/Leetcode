class Solution {
public:
    int numRollsToTarget(int n, int f, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 2, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                int ways = 0;
                for(int k = 1; k <= f; k++) 
                    if(j - k >= 0) ways = (ways + dp[i - 1][j - k]) % 1000000007;
                dp[i][j] = ways % 1000000007;
            }
        }
        return dp[n][target];
    }
};
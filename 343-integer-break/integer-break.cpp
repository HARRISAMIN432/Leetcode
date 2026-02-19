class Solution {
public:
    int f(int n, vector<int> &dp) {
        if (n == 1) return 1;   
        if (dp[n] != -1) return dp[n];
        int ans = 0;
        for (int i = 1; i < n; i++) ans = max(ans, max(i * (n - i), i * f(n - i, dp)));
        return dp[n] = ans;
    }

    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1, dp[0] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};

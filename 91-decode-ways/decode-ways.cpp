class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return f(s.size() - 1, s, dp);
    }

private:
    int f(int i, string &s, vector<int> &dp) {
        if(i < 0) return 1;
        if(dp[i] != -1) return dp[i];
        int ways = 0;
        if(s[i] != '0') ways += f(i - 1, s, dp);
        if(i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))) 
            ways += f(i - 2, s, dp);
        return dp[i] = ways;
    }
};
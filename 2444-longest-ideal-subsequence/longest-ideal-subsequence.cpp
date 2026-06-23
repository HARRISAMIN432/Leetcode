class Solution {
public:
    int longestIdealString(string s, int k) {
        this->s = s;
        this->k = k;
        dp.assign(s.size() + 1, vector<int>(27, -1));
        return f(0, -1);
    }

private:
    string s;
    int k;
    vector<vector<int>> dp;

    int f(int i, int prev) {
        if (i == s.size()) return 0;
        int prevIdx = prev + 1; 
        if (dp[i][prevIdx] != -1) return dp[i][prevIdx];
        int skip = f(i + 1, prev), take = 0, cur = s[i] - 'a';
        if (prev == -1 || abs(cur - prev) <= k) 
            take = 1 + f(i + 1, cur);
        return dp[i][prevIdx] = max(take, skip);
    }
};
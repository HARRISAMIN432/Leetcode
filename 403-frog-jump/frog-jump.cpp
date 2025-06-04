class Solution {
public:
    bool helper(int idx, int k, vector<int>& stones, vector<vector<int>>& dp) {
        if(idx == stones.size() - 1) return true;
        if(k <= 0) return false;
        if(dp[idx][k] == 1) return true;
        if(dp[idx][k] == 0) return false;
        for(int i = idx; i < stones.size(); i++) {
            if(stones[idx] + k < stones[i]) {
                dp[idx][k] = 0;
                return false;
            }
            if(stones[idx] + k == stones[i]) {
                dp[i][k - 1] = helper(i, k - 1, stones, dp);
                dp[i][k] = helper(i, k, stones, dp);
                dp[i][k + 1] = helper(i, k + 1, stones, dp);
                return (max(dp[i][k - 1],max( dp[i][k], dp[i][k + 1]))) ? true : false;
            }
        }
        dp[idx][k] = 0;
        return false;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] > 1)
            return false;
        vector<vector<int>> dp(stones.size(),
                               vector<int>(stones.size() + 1, -1));
        return helper(0, 1, stones, dp);
    }
};
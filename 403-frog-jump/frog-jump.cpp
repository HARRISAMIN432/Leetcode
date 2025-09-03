class Solution {
public:
    bool helper(int idx, int k, vector<int>& stones, vector<vector<int>>& dp) {
        if(idx == stones.size() - 1) return 1;
        if(idx >= stones.size() || k <= 0) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];
        for(int i = idx + 1; i < stones.size(); i++) 
            if(stones[idx] + k == stones[i]) 
                return dp[i][k] = helper(i, k - 1, stones, dp) || helper(i, k, stones, dp) || helper(i, k + 1, stones, dp); 
        return false;
    }

    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), -1));
        return helper(0, 1, stones, dp);
    }
};
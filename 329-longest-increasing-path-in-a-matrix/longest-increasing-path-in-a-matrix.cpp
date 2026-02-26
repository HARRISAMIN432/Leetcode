class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ans = 1;
        for(int i = 0; i < matrix.size(); i++) 
            for(int j = 0; j < matrix[0].size(); j++) 
                ans = max(ans ,dfs(i, j, -1, -1, matrix, dp));
        return ans;
    }

private:
    int dfs(int i, int j, int previ, int prevj, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) return INT_MIN;
        if (previ != -1 && matrix[i][j] <= matrix[previ][prevj]) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = 1 + max({dfs(i + 1, j, i, j, matrix, dp),
                                   dfs(i - 1, j, i, j, matrix, dp),
                                   dfs(i, j + 1, i, j, matrix, dp),
                                   dfs(i, j - 1, i, j, matrix, dp)});
    }
};
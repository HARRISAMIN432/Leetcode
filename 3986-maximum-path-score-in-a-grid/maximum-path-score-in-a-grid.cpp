class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        if(grid.size() == 1 && grid[0].size() == 1 && grid[0][0] == 0 && k == 0) return 0;
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k + 1, -1)));
        f(0, 0, k, grid, dp);
        return dp[0][0][k] < 0 ? -1 : dp[0][0][k];
    }

private:
    int f(int i, int j, int k, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        if(k < 0 || i == grid.size() || j == grid[0].size()) return INT_MIN;
        if(i == grid.size() - 1 && j == grid[0].size() - 1) {
            if(grid[i][j] == 0) return 0;
            return (k >= 1) ? grid[i][j] : INT_MIN; 
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(grid[i][j] == 0) return dp[i][j][k] = max(f(i + 1, j, k, grid, dp), f(i, j + 1, k, grid, dp));
        else return dp[i][j][k] = grid[i][j] + max(f(i + 1, j, k - 1, grid, dp), f(i, j + 1, k - 1, grid, dp));
    }
};
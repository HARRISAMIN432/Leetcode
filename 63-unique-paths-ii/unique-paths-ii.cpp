class Solution {
public:
    int fn(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i == grid.size() || j == grid[0].size() || grid[i][j] == 1) return 0;
        if(i == grid.size() - 1 && j == grid[0].size() - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = fn(i + 1, j, grid, dp) + fn(i, j + 1, grid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1) return 0;
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return fn(0, 0, obstacleGrid, dp);
    }
};
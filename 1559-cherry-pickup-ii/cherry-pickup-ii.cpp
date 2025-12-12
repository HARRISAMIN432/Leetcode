class Solution {
public:
    long long f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
            return -1e9;
        if (i == n-1) {
            if (j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        long long maxi = -1e9;
        for (int a = -1; a <= 1; a++) {
            for (int b = -1; b <= 1; b++) {
                long long value = 0;
                if (j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];

                value += f(i + 1, j1 + a, j2 + b, grid, dp);

                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m - 1, grid, dp);
    }
};

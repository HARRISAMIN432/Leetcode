class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        this->n = board.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(2, -1)));
        this->grid = board;
        vector<int> ans = f(n - 1, n - 1);
        if(ans[0] < 0) return {0, 0};
        return ans;
    }

private:
    const int MOD = 1e9 + 7;
    int n;
    vector<vector<vector<int>>> dp;
    vector<string> grid;

    vector<int> f(int i, int j) {
        if(!isValid(i, j) || grid[i][j] == 'X') return {INT_MIN, 0};
        if(i == 0 && j == 0) return {0, 1};
        if(dp[i][j][1] != -1) return dp[i][j];
        auto l = f(i-1,j), u = f(i,j-1), d = f(i-1,j-1);
        int best = max({l[0], u[0], d[0]});
        if(best == INT_MIN) return dp[i][j] = {INT_MIN, 0};
        int ways = 0;
        if(l[0] == best) ways = (ways + l[1]) % MOD;
        if(u[0] == best) ways = (ways + u[1]) % MOD;
        if(d[0] == best) ways = (ways + d[1]) % MOD;
        int val = (grid[i][j] == 'S') ? 0 : grid[i][j] - '0';
        return dp[i][j] = {best + val, ways};
    }

    bool isValid(int i, int j) {
        return i >= 0 && j >= 0 && i < grid.size() && j < grid.size();
    }
};
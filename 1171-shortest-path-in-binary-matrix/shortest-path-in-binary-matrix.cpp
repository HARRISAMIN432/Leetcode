class Solution {
public:
    bool isValid(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1 || grid[grid.size() - 1][grid.size() - 1] == 1) return -1;
        if(grid.size() == 1 && grid[0][0] == 0) return 1;
        int row[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int col[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int n = grid.size();
        int ans = INT_MAX;
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 0});
        grid[0][0] = 1;
        while (!q.empty()) {
            int r = q.front().first.first, c = q.front().first.second,
                d = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++) {
                if (isValid(r + row[i], c + col[i], n) && grid[r+row[i]][c+col[i]] == 0 &&
                    r + row[i] == n - 1 && c + col[i] == n - 1)
                    ans = min(ans, d + 1);
                else if (isValid(r + row[i], c + col[i], n) && grid[r+row[i]][c+col[i]] == 0) {
                    q.push({{r + row[i], c + col[i]}, d + 1});
                    grid[r + row[i]][c + col[i]] = 1;
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans + 1;
    }
};
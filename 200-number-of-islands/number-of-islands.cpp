class Solution {
public:
    bool isValid(int i, int j, int r, int c) {
        return i < r && i >= 0 && j >= 0 && j < c;
    }

    void bfs(int i, int j, vector<vector<bool>>& visited,
             vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (isValid(r + 1, c, grid.size(), grid[0].size()) &&
                grid[r + 1][c] == '1' && !visited[r + 1][c]) {
                q.push({r + 1, c});
                visited[r + 1][c] = 1;
            }
            if (isValid(r - 1, c, grid.size(), grid[0].size()) &&
                grid[r - 1][c] == '1' && !visited[r - 1][c]) {
                q.push({r - 1, c});
                visited[r - 1][c] = 1;
            }
            if (isValid(r, c + 1, grid.size(), grid[0].size()) &&
                grid[r][c + 1] == '1' && !visited[r][c + 1]) {
                q.push({r, c + 1});
                visited[r][c + 1] = 1;
            }
            if (isValid(r, c - 1, grid.size(), grid[0].size()) &&
                grid[r][c - 1] == '1' && !visited[r][c - 1]) {
                q.push({r, c - 1});
                visited[r][c - 1] = 1;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ans++;
                    bfs(i, j, visited, grid);
                }
            }
        }
        return ans;
    }
};
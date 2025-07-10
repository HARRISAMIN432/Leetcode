class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& grid) {
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size();
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = 1;
                    q.push({i, j});
                    int temp = 1;
                    while (!q.empty()) {
                        int r = q.front().first, c = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            if (isValid(r + row[k], c + col[k], grid) &&
                                grid[r + row[k]][c + col[k]] == 1 &&
                                !visited[r + row[k]][c + col[k]]) {
                                visited[r + row[k]][c + col[k]] = 1;
                                q.push({r + row[k], c + col[k]});
                                temp++;
                            }
                        }
                    }
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};
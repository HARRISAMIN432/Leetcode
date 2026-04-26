class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<pair<int, int>, pair<int, int>>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j]) {
                    q.push({{-1, -1}, {i, j}});
                    while (!q.empty()) {
                        int parX = q.front().first.first, parY = q.front().first.second;
                        int currX = q.front().second.first, currY = q.front().second.second;
                        q.pop();
                        visited[currX][currY] = true;
                        for (int i = 0; i < 4; i++) {
                            int nextX = currX + moveX[i], nextY = currY + moveY[i];
                            if (isValid(nextX, nextY, grid) &&
                                grid[nextX][nextY] == grid[currX][currY])
                                if (visited[nextX][nextY] && (nextX != parX || nextY != parY))
                                    return true;
                                else if (visited[nextX][nextY])
                                    continue;
                                else
                                    q.push({{currX, currY}, {nextX, nextY}});
                        }
                    }
                }
            }
        }
        return false;
    }

private:
    bool isValid(int i, int j, vector<vector<char>>& grid) {
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size();
    }

    int moveX[4] = {-1, 0, 1, 0};
    int moveY[4] = {0, 1, 0, -1};
};
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if(health == 1 && grid[0][0] == 1) return false;
        priority_queue<tuple<int, int, int>> q;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        vis[0][0] = true;
        q.push({(grid[0][0] == 0 ? health : health - 1) ,0, 0 });
        while(!q.empty()) {
            auto [h, x, y] = q.top(); q.pop();
            if(h <= 0) continue;
            if(x == grid.size() - 1 && y == grid[0].size() - 1 && h) return true;
            for(int i = 0; i < 4; i++) {
                int nX = x + row[i], nY = y + col[i];
                if(isValid(nX, nY, grid) && !vis[nX][nY]) {
                    vis[nX][nY] = true;
                    q.push({(grid[nX][nY] == 0 ? h : h - 1) ,nX, nY});
                }
            }
        }
        return false;
    }    

private:
    int row[4] = {-1, 0, 1, 0}, col[4] = {0, -1, 0, 1};

    bool isValid(int x, int y, vector<vector<int>>& grid) {
        return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
    }
};
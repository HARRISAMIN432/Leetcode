class Solution {
public:
    bool valid(int i, int j, int r, int c) { return i >= 0 && i < r && j >= 0 && j < c; }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(), c = grid[0].size(), ans = 0;
        queue<pair<int, int>> q;
        int rows[4] = {0, 0, -1, 1};
        int cols[4] = {-1, 1, 0, 0};
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == '1') {
                    grid[i][j] = '0';
                    ans++;
                    q.push(make_pair(i, j));
                }
                while(!q.empty()) {
                    int row = q.front().first, col = q.front().second;
                    q.pop();
                    for(int k = 0; k < 4; k++) if(valid(row + rows[k], col + cols[k], r, c)) 
                        if(grid[row + rows[k]][col + cols[k]] == '1') {
                            grid[row + rows[k]][col + cols[k]] = '0';
                            q.push(make_pair(row + rows[k], col + cols[k]));
                        }
                } 
            }
        }
        return ans;
    }
};
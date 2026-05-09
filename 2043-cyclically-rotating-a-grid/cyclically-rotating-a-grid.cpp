class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        int startRow = 0, endRow = n - 1, startCol = 0, endCol = m - 1;
        while(startRow < endRow && startCol < endCol) {
            vector<int> layer;
            int len = 2 * (endCol - startCol) + 2 * (endRow - startRow);
            int tk = k % len, i = startRow, j = startCol;
            while(j < endCol) {
                layer.push_back(grid[i][j]);
                j++;
            }
            while(i < endRow) {
                layer.push_back(grid[i][j]);
                i++;
            }
            while(j > startCol) {
                layer.push_back(grid[i][j]);
                j--;
            }
            while(i > startRow) {
                layer.push_back(grid[i][j]);
                i--;
            } 
            while(tk--) {
                layer.push_back(layer[0]);
                layer.erase(layer.begin());
            }
            int p = 0;
            i = startRow, j = startCol;
            while(j < endCol) {
                ans[i][j] = layer[p];
                j++, p++;
            }
            while(i < endRow) {
                ans[i][j] = layer[p];
                i++, p++;
            }
            while(j > startCol) {
                ans[i][j] = layer[p];
                j--, p++;
            }
            while(i > startRow) {
                ans[i][j] = layer[p];
                i--, p++;
            } 
            startRow++, endRow--, startCol++, endCol--; 
        } 
        return ans; 
    }
};
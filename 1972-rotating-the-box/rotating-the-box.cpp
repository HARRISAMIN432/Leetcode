class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        vector<vector<char>> ans(m, vector<char>(n));
        for(int i = 0; i < m; i++) {
            vector<char> temp;
            for(int j = n - 1; j >= 0; j--) 
                temp.push_back(boxGrid[j][i]);
            ans[i] = temp;
        }
       for(int j = 0; j < n; j++) {
            int emptyRow = m - 1;
            for(int i = m - 1; i >= 0; i--) {
                if(ans[i][j] == '*') {
                    emptyRow = i - 1;
                } 
                else if(ans[i][j] == '#') {
                    swap(ans[i][j], ans[emptyRow][j]);
                    emptyRow--;
                }
            }
        }
        return ans; 
    }
};
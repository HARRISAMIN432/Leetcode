class Solution {
public:
    void helper(int n, int col, vector<bool>& rows, vector<bool>& cols,
                vector<bool>& md, vector<bool>& ad, vector<string>& temp,
                vector<vector<string>>& ans) {
        if (col == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!rows[i] && !cols[col] && !ad[i - col + n - 1] && !md[col + i]) {
                temp[i][col] = 'Q';
                rows[i] = 1, cols[col] = 1, ad[i - col + n - 1] = 1, md[i + col] = 1;
                helper(n, col + 1, rows, cols, md, ad, temp, ans);
                temp[i][col] = '.';
                rows[i] = cols[col] = false;
                ad[i - col + n - 1] = md[i + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<bool> rows(n, 0);
        vector<bool> cols(n, 0);
        vector<bool> md(2*n, 0);
        vector<bool> ad(2*n, 0);
        vector<string> temp(n, string(n, '.'));
        helper(n, 0, rows, cols, md, ad, temp, ans);
        return ans;
    }
};
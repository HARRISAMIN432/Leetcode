class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            vector<int> tmp;
            for(int j = n - 1; j >= 0; j--) 
                tmp.push_back(matrix[j][i]);
            ans[i] = tmp;
        }
        matrix = ans;
    }
};
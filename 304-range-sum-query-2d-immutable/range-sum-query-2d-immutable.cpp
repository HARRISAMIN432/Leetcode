class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix.resize(matrix.size());
        for(int i = 0; i < matrix.size(); i++) prefix[i].resize(matrix[0].size());
        prefix[0][0] = matrix[0][0];
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                prefix[i][j] = matrix[i][j];
                if(i > 0) prefix[i][j] += prefix[i-1][j];
                if(j > 0) prefix[i][j] += prefix[i][j-1];
                if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int res = prefix[r2][c2];
        if(r1 > 0) res -= prefix[r1 - 1][c2];
        if(c1 > 0) res -= prefix[r2][c1 - 1];
        if(r1 > 0 && c1 > 0) res += prefix[r1 - 1][c1 - 1];
        return res;
    }

private:
    vector<vector<long long>> prefix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
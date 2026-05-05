class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<vector<char>> mat(numRows, vector<char>(s.size(), '?'));
        int iter = 0, i = 0, j = 0;
        char dir = 'V';
        while(iter < s.size()) {
            mat[i][j] = s[iter];
            iter++;
            if(dir == 'V') {
                if(i == numRows - 1) {
                    dir = 'D';
                    i--; j++;
                } else {
                    i++;
                }
            } 
            else {
                if(i == 0) {
                    dir = 'V';
                    i++;
                } else {
                    i--; j++;
                }
            }
        }
        string ans;
        for(int row = 0; row < numRows; row++) 
            for(int col = 0; col < s.size(); col++) 
                if(mat[row][col] != '?') 
                    ans.push_back(mat[row][col]);
        return ans;
    }
};
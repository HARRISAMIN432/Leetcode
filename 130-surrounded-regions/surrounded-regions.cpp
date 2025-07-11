class Solution {
public:
    bool isValid(int i, int j, vector<vector<char>>& board) {
        return i < board.size() && j < board[0].size() && i >= 0 && j >= 0;
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(),
                                     vector<bool>(board[0].size(), 0));
        queue<pair<int, int>> q;
        int rows[] = {-1, 0, 1, 0};
        int cols[] = {0, 1, 0, -1};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    q.push({i, j});
                    vector<pair<int, int>> idx;
                    idx.push_back({i, j});
                    visited[i][j] = 1;
                    bool change = true;
                    while (!q.empty()) {
                        int r = q.front().first, c = q.front().second;
                        if (r == board.size() - 1 || c == board[0].size() - 1 || r == 0 || c == 0)
                            change = false;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            if (isValid(r + rows[k], c + cols[k], board) &&
                                !visited[r + rows[k]][c + cols[k]] && board[r + rows[k]][c + cols[k]] == 'O') {
                                q.push({r + rows[k], c + cols[k]});
                                visited[r + rows[k]][c + cols[k]] = true;
                                idx.push_back({r + rows[k], c + cols[k]});
                            }
                        }
                    }
                    if(change) 
                        for(int i = 0; i < idx.size(); i++) 
                            board[idx[i].first][idx[i].second] = 'X';
                }
            }
        }
    }
};
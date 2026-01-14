class Solution {
public:
    void f(int i, int j, vector<vector<bool>>& rows, vector<vector<bool>>& cols,
           vector<vector<bool>>& boxes, vector<vector<char>>& board) {
        if (solved)
            return;
        if (j == 9) {
            solved = true;
            return;
        }
        if (i == 9) {
            f(0, j + 1, rows, cols, boxes, board);
            return;
        }
        if (board[i][j] != '.') {
            f(i + 1, j, rows, cols, boxes, board);
            return;
        }
        for (int num = 1; num <= 9; num++) {
            if (cols[j][num] == false && rows[i][num] == false) {
                if (i >= 0 && i <= 2) {
                    if (j >= 0 && j <= 2 && boxes[0][num] == false) {
                        board[i][j] = num + '0';
                        rows[i][num] = true;
                        cols[j][num] = true;
                        boxes[0][num] = true;
                        f(i + 1, j, rows, cols, boxes, board);
                        if (solved)
                            return;
                        rows[i][num] = false;
                        cols[j][num] = false;
                        boxes[0][num] = false;
                        board[i][j] = '.';
                    } else if (j >= 3 && j <= 5 && boxes[1][num] == false) {
                        board[i][j] = num + '0';
                        rows[i][num] = true;
                        cols[j][num] = true;
                        boxes[1][num] = true;
                        f(i + 1, j, rows, cols, boxes, board);
                        if (solved)
                            return;
                        rows[i][num] = false;
                        cols[j][num] = false;
                        boxes[1][num] = false;
                        board[i][j] = '.';
                    } else if (j >= 6 && j <= 8 && boxes[2][num] == false) {
                        board[i][j] = num + '0';
                        rows[i][num] = true;
                        cols[j][num] = true;
                        boxes[2][num] = true;
                        f(i + 1, j, rows, cols, boxes, board);
                        if (solved)
                            return;
                        rows[i][num] = false;
                        cols[j][num] = false;
                        boxes[2][num] = false;
                        board[i][j] = '.';
                    }
                } else if (i >= 3 && i <= 5) {
                    if (j >= 0 && j <= 2 && boxes[3][num] == false) {
                        board[i][j] = num + '0';
                        rows[i][num] = true;
                        cols[j][num] = true;
                        boxes[3][num] = true;
                        f(i + 1, j, rows, cols, boxes, board);
                        if (solved)
                            return;
                        rows[i][num] = false;
                        cols[j][num] = false;
                        boxes[3][num] = false;
                        board[i][j] = '.';
                    } else if (j >= 3 && j <= 5 && boxes[4][num] == false) {
                        board[i][j] = num + '0';
                        rows[i][num] = true;
                        cols[j][num] = true;
                        boxes[4][num] = true;
                        f(i + 1, j, rows, cols, boxes, board);
                        if (solved)
                            return;
                        rows[i][num] = false;
                        cols[j][num] = false;
                        boxes[4][num] = false;
                        board[i][j] = '.';
                    } else if (j >= 6 && j <= 8 && boxes[5][num] == false) {
                        board[i][j] = num + '0';
                        rows[i][num] = true;
                        cols[j][num] = true;
                        boxes[5][num] = true;
                        f(i + 1, j, rows, cols, boxes, board);
                        if (solved)
                            return;
                        rows[i][num] = false;
                        cols[j][num] = false;
                        boxes[5][num] = false;
                        board[i][j] = '.';
                    }
                } else {
                    if (j >= 0 && j <= 2 && boxes[6][num] == false) {
                        board[i][j] = num + '0';
                        rows[i][num] = true;
                        cols[j][num] = true;
                        boxes[6][num] = true;
                        f(i + 1, j, rows, cols, boxes, board);
                        if (solved)
                            return;
                        rows[i][num] = false;
                        cols[j][num] = false;
                        boxes[6][num] = false;
                        board[i][j] = '.';
                    } else if (j >= 3 && j <= 5 && boxes[7][num] == false) {
                        board[i][j] = num + '0';
                        rows[i][num] = true;
                        cols[j][num] = true;
                        boxes[7][num] = true;
                        f(i + 1, j, rows, cols, boxes, board);
                        if (solved)
                            return;
                        rows[i][num] = false;
                        cols[j][num] = false;
                        boxes[7][num] = false;
                        board[i][j] = '.';
                    } else if (j >= 6 && j <= 8 && boxes[8][num] == false) {
                        board[i][j] = num + '0';
                        rows[i][num] = true;
                        cols[j][num] = true;
                        boxes[8][num] = true;
                        f(i + 1, j, rows, cols, boxes, board);
                        if (solved)
                            return;
                        rows[i][num] = false;
                        cols[j][num] = false;
                        boxes[8][num] = false;
                        board[i][j] = '.';
                    }
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> cols(9, vector<bool>(10, false)),
            rows(9, vector<bool>(10, false)), boxes(9, vector<bool>(10, false));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    cols[j][board[i][j] - '0'] = 1;
                    rows[i][board[i][j] - '0'] = 1;
                }
            }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != '.')
                    boxes[0][board[i][j] - '0'] = 1;
        for (int i = 0; i < 3; i++)
            for (int j = 3; j < 6; j++)
                if (board[i][j] != '.')
                    boxes[1][board[i][j] - '0'] = 1;
        for (int i = 0; i < 3; i++)
            for (int j = 6; j < 9; j++)
                if (board[i][j] != '.')
                    boxes[2][board[i][j] - '0'] = 1;
        for (int i = 3; i < 6; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != '.')
                    boxes[3][board[i][j] - '0'] = 1;
        for (int i = 3; i < 6; i++)
            for (int j = 3; j < 6; j++)
                if (board[i][j] != '.')
                    boxes[4][board[i][j] - '0'] = 1;
        for (int i = 3; i < 6; i++)
            for (int j = 6; j < 9; j++)
                if (board[i][j] != '.')
                    boxes[5][board[i][j] - '0'] = 1;
        for (int i = 6; i < 9; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != '.')
                    boxes[6][board[i][j] - '0'] = 1;
        for (int i = 6; i < 9; i++)
            for (int j = 3; j < 6; j++)
                if (board[i][j] != '.')
                    boxes[7][board[i][j] - '0'] = 1;
        for (int i = 6; i < 9; i++)
            for (int j = 6; j < 9; j++)
                if (board[i][j] != '.')
                    boxes[8][board[i][j] - '0'] = 1;
        f(0, 0, rows, cols, boxes, board);
    }

private:
    bool solved = false;
};
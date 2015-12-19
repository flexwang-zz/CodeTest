class Solution {
public:
    bool row[9][9], col[9][9], sq[9][9];
    void solveSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++)
        for (int j=0; j<9; j++)
            if (board[i][j] != '.') 
                fill(i, j, board[i][j]-'1');
        go(0, 0, board);
    }
    
    bool go(int i, int j, vector<vector<char>> &board) {
        if (i > 8) return true;
        if (board[i][j] != '.') {
            next(i, j);
            return go(i, j, board);
        }
        int i0 = i, j0 = j;
        next(i, j);
        for (int k=0; k<9; k++) {
            if (check(i0, j0, k)) {
                fill(i0, j0, k);
                if (go(i, j, board)) {
                    board[i0][j0] = k+'1';
                    return true;
                }
                unfill(i0, j0, k);
            }
        }
        return false;
    }
    
    void next(int &i, int &j) {
        if (j == 8) {
            i++;
            j = 0;
        }
        else
            j++;
    }
    
    void fill(int i, int j, int n) {
        row[i][n] = true;
        col[j][n] = true;
        sq[i/3*3+j/3][n] = true;
    }
    
    void unfill(int i, int j, int n) {
        row[i][n] = false;
        col[j][n] = false;
        sq[i/3*3+j/3][n] = false;  
    }
    
    bool check(int i, int j, int n) {
        return !(row[i][n] || col[j][n] || sq[i/3*3+j/3][n]);
    }
};
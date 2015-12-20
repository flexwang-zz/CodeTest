class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = m==0?0:board[0].size();
        if (n==0) return;
        vector<vector<int>> dup = board;
        for (int i=0; i<m; i++)
        for (int j=0; j<n; j++) {
            const static int di[]={-1, -1, 0, 1, 1, 1, 0, -1};
            const static int dj[]={0, 1, 1, 1, 0, -1, -1, -1};
            int nlive = 0;
            for (int k=0; k<8; k++) {
                int x = i+di[k], y= j+dj[k];
                if (x < 0 || x >=m || y<0 || y>=n) continue;
                if (dup[x][y]) nlive++;
            }
            if (nlive < 2) board[i][j] = 0;
            else if (nlive > 3) board[i][j] = 0;
            if (nlive == 3) board[i][j] = 1;
        }
    }
};
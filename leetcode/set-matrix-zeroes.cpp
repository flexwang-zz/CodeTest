class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m==0?0:matrix[0].size();
        bool first_r = false, first_c = false;
        
        for (int i=0; i<m; i++)
        for (int j=0; j<n; j++) {
            if (matrix[i][j]==0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
                if (i == 0) first_r = true;
                if (j == 0) first_c = true;
            }
        }
        
        for (int i=1; i<m; i++)
        if (matrix[i][0] == 0)
        for (int j=1; j<n; j++)
            matrix[i][j] = 0;
        for (int i=1; i<n; i++)
        if (matrix[0][i] == 0)
        for (int j=1; j<m; j++)
            matrix[j][i] = 0;
        if (first_r)
        for (int i=0; i<n; i++)
            matrix[0][i] = 0;
        if (first_c)
        for (int i=0; i<m; i++)
            matrix[i][0] = 0;
    }
};
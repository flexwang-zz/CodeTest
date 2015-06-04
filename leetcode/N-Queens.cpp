class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<int> col(n);
        solveNQueens(ans, col, 0, n);
        return ans;
    }
    
    void solveNQueens(vector<vector<string> > &ans, vector<int>& col, int i, int n) {
        if (i == n) {
            print(ans, col);
            return;
        }
        for (int j=0; j<n; j++) {
            col[i] = j;
            if (valid(col, i))
                solveNQueens(ans, col, i+1, n);
        }
    }
    
    bool valid(const vector<int>& col, int i) {
        for (int j=0; j<i; j++) {
            int diff = col[j] - col[i];
            if (diff == 0 || diff == i-j || diff == j-i)
                return false;
        }
        return true;
    }
    
    void print(vector<vector<string> > &ans, const vector<int>& col) {
        vector<string> v;
        int n = col.size();
        for (int i=0; i<n; i++) {
            string str;
            for (int j=0; j<n; j++) 
                str += col[j] == i? 'Q':'.';
            v.push_back(str);
        }
        ans.push_back(v);
    }
};
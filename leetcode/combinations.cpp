class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
           vector<vector<int>> ans;
           vector<int> comb;
           combine(ans, comb, k, n, 0);
           return ans;
    }
    
    void combine(vector<vector<int>> &ans, vector<int>& comb, int k, int n, int begin)
    {
        if (comb.size() == k) {
            ans.push_back(comb);
            return;
        }
        
        for (int i=begin+1; i<=n; i++) {
            comb.push_back(i);
            combine(ans, comb, k, n, i);
            comb.pop_back();
        }
    }
};
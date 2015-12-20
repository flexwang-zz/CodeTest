class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> strs;
        generateParenthesis(strs, string(), n, n);
        return strs;
    }
    
    void generateParenthesis(vector<string>& strs,string str, int l, int r) {
        if (l==0 && r==0)
            strs.push_back(str);
        if (l > 0)
            generateParenthesis(strs, str+'(', l-1, r);
        if (r > l)
            generateParenthesis(strs, str+')', l, r-1);
    }
};
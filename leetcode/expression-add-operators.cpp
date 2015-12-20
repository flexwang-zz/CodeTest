class Solution {
public:
    void helper(vector<string>& ans, int s, string ex, string &num, long long cur, long long last, int target) {
        if (s == num.length()) {
            if (cur == target)
                ans.push_back(ex);
            return;
        }
        long long n = 0;
        for (int i = s; i<num.length(); i++) {
            n = n * 10 + num[i] - '0';
            if (num[s] == '0' && i>s) return;
            string this_num = num.substr(s, i - s + 1);
            if (ex == "") {
                helper(ans, i + 1, this_num, num, n, n, target);
            }
            else {
                helper(ans, i + 1, ex + "+" + this_num, num, cur + n, n, target);
                helper(ans, i + 1, ex + "-" + this_num, num, cur - n, -n, target);
                helper(ans, i + 1, ex + "*" + this_num, num, cur - last + last*n, last*n, target);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(ans, 0, "", num, 0, 0, target);
        return ans;
    }
};
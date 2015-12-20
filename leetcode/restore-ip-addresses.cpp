class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string t(s.length() + 3,' ');
        gao(s, ans, t, 0, 0);
        return ans;
    }

    void gao(string &s, vector<string>& ans, string& t, int begin, int idx) {
        if (begin == s.length() && idx == 4) {
            ans.push_back(t);
            return;
        }
        if (idx >= 4 || begin >= s.length()) return;
        int ip = 0;
        for (int i = 0; i<3 && begin + i<s.length(); i++) {
            if (ip==0 && i) break;
            ip = ip * 10 + s[i + begin] - '0';
            if (ip > 255) break;
            t[begin + idx + i] = s[i + begin];
            if (idx < 3) t[begin + idx + i + 1] = '.';
            gao(s, ans, t, begin + i + 1, idx + 1);
        }
    }
};
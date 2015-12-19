class Solution {
public:
    void reverseWords(string &s) {
        if (s.length() == 0) return;
        reverse(s.begin(), s.end());
        int p1 = 0, p2;
        int len = 0;
        for (p2=0; p2<s.length(); p2++) 
            if (s[p2] == ' ') {
                if (len) {
                    reverse(s.begin()+p1, s.begin()+p2);
                    p1 = p1+len+1;
                    len = 0;
                }
            }
            else
                len++;
        if (len) {
            reverse(s.begin()+p1, s.begin()+p2);
            p1 = p1 + len + 1;
        }
        s.resize(max(p1-1, 0));
    }
};
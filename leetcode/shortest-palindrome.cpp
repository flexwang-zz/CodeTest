class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        string str = s+'.'+t+'.';
        vector<int> next;
        getNext(str, next);
        int sn = s.length();
        return t.substr(0, sn-next.back())+s;
    }
    
    void getNext(string &s, vector<int> &next) {
        int len = s.length();
        next.resize(len);
        next[0] = -1;
        for (int i=1; i<len; i++) {
            int k = next[i-1];
            while (k>= 0 && s[k] != s[i-1])
                k = next[k];
            next[i] = k+1;
        }
    }
};
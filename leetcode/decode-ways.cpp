class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len==0) return 0;
        int dp[len+1];
        dp[0] = 1;
        for (int i=1; i<=len; i++) {
            dp[i] = 0;
            if (s[i-1] != '0')
                dp[i] += dp[i-1];
            if (i-2>=0 && s[i-2]!='0' && (s[i-2]-'0')*10+s[i-1]-'0' <= 26)
                dp[i] += dp[i-2];
        }
        return dp[len];
    }
};
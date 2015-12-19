class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len1+len2!=len3) return false;
        
        vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
        
        dp[0][0] = true;
        for (int i=0; i<len1&&s1[i]==s3[i]; i++)
            dp[i+1][0] = true;
        for (int i=0; i<len2&&s2[i]==s3[i]; i++) 
            dp[0][i+1] = true;
        
        for (int i=0; i<len1; i++)
        for (int j=0; j<len2; j++) {
            if (dp[i][j+1]&&s1[i]==s3[i+j+1] 
                || dp[i+1][j]&&s2[j]==s3[i+j+1])
                dp[i+1][j+1] = true;
        }
        
        return dp[len1][len2];
    }
};
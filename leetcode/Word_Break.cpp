class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.length();
        int max_len = 0, min_len = len+1;
        for (unordered_set<string>::iterator iter=wordDict.begin(); iter!=wordDict.end(); ++iter) {
            max_len = max(max_len, (int)iter->length());
            min_len = min(min_len, (int)iter->length());
        }
        
        vector<bool> dp(len+1, false);
        dp[len] = true;
        for (int i=len-1; i>=0; i--) {
            for (int j=min_len; j<=min(max_len, len-i); j++)
                if (dp[i+j] && wordDict.find(s.substr(i, j)) != wordDict.end()) {
                    dp[i] = true;
                }
        }
        
        return dp[0];
    }
};
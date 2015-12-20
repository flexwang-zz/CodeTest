class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> ans;
        int min_len = INT_MAX, max_len = INT_MIN;
        for (unordered_set<string>::iterator iter=wordDict.begin(); iter != wordDict.end(); iter++) {
            min_len = min(min_len, (int)iter->length());
            max_len = max(max_len, (int)iter->length());
        }
        if (!canWordBreak(s, wordDict, min_len, max_len))
            return ans;
        wordBreak(s, wordDict, string(), ans, min_len, max_len);
        return ans;
    }
    
    void wordBreak(string s, unordered_set<string>& wordDict, string v, vector<string>& ans, int min_len, int max_len) {
        if (s.length() == 0) {
            ans.push_back(v);
            return;
        }
        if (v.length() != 0) v.push_back(' ');
        for (int i=min_len; i<=s.length() && i<=max_len; i++) {
            string t = s.substr(0, i);
            if (wordDict.find(t) != wordDict.end())
                wordBreak(s.substr(i), wordDict, v+t, ans, min_len, max_len);
        }
    }
    
    bool canWordBreak(std::string &s, std::unordered_set<std::string> &wordDict, int min_len, int max_len) {
        int len = s.length();
        vector<bool> dp(len+1, false);
        dp[0] = true;
        for (int i=1; i<=len; i++) 
        for (int l=min_len; l<=max_len && i-l>=0; l++) 
            if (dp[i-l] && wordDict.count(s.substr(i-l, l))) {
                dp[i] = true;
                break;
            }
        return dp[len];
    }
};
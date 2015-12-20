class Solution {
public:
    string longestPalindrome(string s) {
        const int max_n = 1001;
        bool dp[max_n][max_n];
        memset(dp, 0, sizeof(dp));

        int len = s.length();
        for (int i = 0; i < len; i++)
        for (int j = 0; j < 2; j++) {
            if (i + j <= len) {
                // printf("%d %d\n", i, j);
                dp[i][i + j] = true;
            }
        }

        for (int l = 2; l <= len; l++)
        for (int i = 0; i < len; i++) {
            if (i + l <= len && dp[i + 1][i + l - 1] && s[i] == s[i + l - 1])
                dp[i][i + l] = true;
        }
        int max_l = 1;
        int max_s = 0;

        for (int i = 0; i < len; i++)
        for (int j = 1; j <= len; j++)
        if (dp[i][i + j] && j > max_l) {
            max_l = j;
            max_s = i;
        }

        return s.substr(max_s, max_l);
    }
};
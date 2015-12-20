class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2) return 0;
        if (k >= prices.size()/2) {
            int ans = 0;
            for (int i=1; i<prices.size(); i++)
                ans += max(0, prices[i]-prices[i-1]);
            return ans;
        }
        vector<int> dp(prices.size());
        for (int i=0; i<k; i++) {
            int t = dp[0]-prices[0];
            dp[0] = 0;
            for (int j=1; j<prices.size(); j++) {
                int temp = max(t, dp[j]-prices[j]);
                dp[j] = max(prices[j]+t, dp[j-1]);
                t = temp;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
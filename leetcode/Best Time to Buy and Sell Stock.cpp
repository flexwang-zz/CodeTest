class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if( prices.size() <= 0)
        {
            return 0;
        }
        
        int min = prices[0];
        int maxprofit = 0;
        
        for( int i=0,size=prices.size(); i<size; i++)
        {
            if( prices[i]-min > maxprofit)
            {
                maxprofit = prices[i]-min;
            }
            if( prices[i] < min)
            {
                min = prices[i];
            }
        }
        
        return maxprofit;
    }
};
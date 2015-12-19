class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        int size = prices.size();
        
        if( size <= 0)
        {
            return 0;
        }
        int profit = 0;
        
        vector<int> p(size, 0);
        
        int min = prices[0];
        int maxprofit = 0;
        for(int i=0; i<size; i++)
        {
            if( prices[i] - min > maxprofit)
            {
                maxprofit = prices[i] - min;
            }
             p[i] = maxprofit;
            
            if( min > prices[i])
            {
                min = prices[i];
            }
        }
        
        int max = prices[size-1];
        maxprofit = 0;
        for(int i=size-1; i>=0; i--)
        {
            if( max-prices[i] > maxprofit)
            {
                maxprofit = max - prices[i];
            }
            if( maxprofit+p[i] > profit)
            {
                profit = maxprofit+p[i];
            }
            
            if( max < prices[i])
            {
                max = prices[i];                
            }
        }
        
        return profit;
    }
};
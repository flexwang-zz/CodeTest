class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        
        if( size <= 0)
        {
            return 0;
        }
        
        int profit = 0;
        int last = prices[0];
        
        for( int i=1; i<size; i++)
        {
            if( last < prices[i])
            {
                profit += prices[i] - last;
            }
            last = prices[i];
        }
        
        return profit;
    }
    
}; 
class Solution {
public:
    int numTrees(int n) {
        return numTrees(0, n-1);
    }
    
    int numTrees(int start, int end)
    {
        if( end - start <= 0)
        {
            return 1;
        }
        
        int result = 0;
        
        for( int i=start; i<=end; i++)
        {
            result += numTrees(start, i-1)*numTrees(i+1,end);
        }
        
        return result;
    }
};
class Solution {
public:
    int singleNumber(int A[], int n) {
        
        int x, i;
        for( i=0, x=0; i<n; i++)
        {
            x = x^A[i];
        }
        
        return x;
    }
};
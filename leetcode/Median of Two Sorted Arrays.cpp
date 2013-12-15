class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        
        double a = (double)findk( A, 0, m-1, B, 0, n-1, (m+n-1)/2);
        double b = (double)findk( A, 0, m-1, B, 0, n-1, (m+n)/2);
        
        return (a+b)/2.0;
        
    }
    
    int findk(int A[], int m1, int m2, int B[], int n1, int n2, int k)
    {
        if( m2 < m1)
        {
            return B[n1+k];
        }
        
        if( n2 < n1)
        {
            return A[m1+k];
        };
        
        int a = (m1+m2+1)/2;
        int b = (n1+n2+1)/2;
        
        int mid = (m2-m1+1)/2 + (n2-n1+1)/2+1;

        if (k >= mid)
        {
            if (A[a]>B[b])
            {
                return findk(A, m1, m2, B, b+1, n2, k-(b-n1)-1);
            }
            else
            {
                return findk(A, a+1, m2, B, n1, n2, k-(a-m1)-1);
            }
        }
        else
        {
            if (A[a]>B[b])
            {
                return findk(A, m1, a-1, B, n1, n2, k);
            }
            else
            {
                return findk(A, m1, m2, B, n1, b-1, k);
            }
        }
    }
};
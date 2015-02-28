/*
Description

Given a two-dimensional array of positive and negative integers, a sub-rectangle is any contiguous sub-array of size 1*1 or greater located within the whole array. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle. 
As an example, the maximal sub-rectangle of the array: 

0 -2 -7 0 
9 2 -6 2 
-4 1 -4 1 
-1 8 0 -2 
is in the lower left corner: 

9 2 
-4 1 
-1 8 
and has a sum of 15. 
Input

The input consists of an N * N array of integers. The input begins with a single positive integer N on a line by itself, indicating the size of the square two-dimensional array. This is followed by N^2 integers separated by whitespace (spaces and newlines). These are the N^2 integers of the array, presented in row-major order. That is, all numbers in the first row, left to right, then all numbers in the second row, left to right, etc. N may be as large as 100. The numbers in the array will be in the range [-127,127].
Output

Output the sum of the maximal sub-rectangle.
Sample Input

4
0 -2 -7 0 9 2 -6 2
-4 1 -4  1 -1

8  0 -2
Sample Output

15
*/
#include <stdio.h>
#include <limits.h>
#include <algorithm>
using std::max;
const int   max_n = 105;
int         a[max_n][max_n];
int         n;
int         ans;
int         dp[max_n+1];

int sum_col(int i, int j, int k) {
    int s = 0;
    for (int l=i; l<j; l++)
        s += a[l][k];
    return s;
}
int main()
{
    scanf("%d", &n);

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            scanf("%d", &a[i][j]);

    ans = INT_MIN;

    for (int i=0; i<n; i++)
        for (int j=i+1; j<=n; j++) 
            for (int k=1; k<=n; k++) {
                int sr = sum_col(i, j, k-1);
                dp[k] = dp[k-1]>0?dp[k-1]+ sr:sr;
                ans = max(dp[k], ans);        
            }

    printf("%d",ans);

    return 0;
}
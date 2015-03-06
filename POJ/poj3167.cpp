/*
Description

The cows don't use actual bowling balls when they go bowling. They each take a number (in the range 0..99), though, and line up in a standard bowling-pin-like triangle like this: 

          7



        3   8



      8   1   0



    2   7   4   4



  4   5   2   6   5
Then the other cows traverse the triangle starting from its tip and moving "down" to one of the two diagonally adjacent cows until the "bottom" row is reached. The cow's score is the sum of the numbers of the cows visited along the way. The cow with the highest score wins that frame. 

Given a triangle with N (1 <= N <= 350) rows, determine the highest possible sum achievable.
Input

Line 1: A single integer, N 

Lines 2..N+1: Line i+1 contains i space-separated integers that represent row i of the triangle.
Output

Line 1: The largest sum achievable using the traversal rules
Sample Input

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
Sample Output

30
Hint

Explanation of the sample: 

          7

         *

        3   8

       *

      8   1   0

       *

    2   7   4   4

       *

  4   5   2   6   5
The highest score is achievable by traversing the cows as shown above.
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
const int   max_n = 360;
int         dp[max_n][max_n];
int         n;
int         b[max_n][max_n];

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        for (int j=0; j<=i; j++)
            scanf("%d", &b[i][j]);
    for (int i=0; i<n; i++)
        dp[n-1][i] = b[n-1][i];
    for (int i=n-2; i>=0; i--)
        for (int j=0; j<=i; j++)
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1])+b[i][j];
    printf("%d\n", dp[0][0]);
    return 0;
}

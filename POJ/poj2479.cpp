/*
Description

Given a set of n integers: A={a1, a2,..., an}, we define a function d(A) as below:

Your task is to calculate d(A).
Input

The input consists of T(<=30) test cases. The number of test cases (T) is given in the first line of the input. 
Each test case contains two lines. The first line is an integer n(2<=n<=50000). The second line contains n integers: a1, a2, ..., an. (|ai| <= 10000).There is an empty line after each case.
Output

Print exactly one line for each test case. The line should contain the integer d(A).
Sample Input

1

10
1 -1 2 2 3 -3 4 -4 5 -5
Sample Output

13
Hint

In the sample, we choose {2,2,3,-3,4} and {5}, then we can get the answer. 

Huge input,scanf is recommended.
*/

#include <stdio.h>
#include <algorithm>
#include <limits.h>

using std::max;

const int   max_n = 50005;
int         a[max_n], dp[max_n];
int         n;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            dp[i+1] = max(a[i], dp[i]+a[i]);
        }

        int back = INT_MIN;
        int ans = INT_MIN;
        int temp = 0;
        for (int i=n-1; i>=1; i--) {
            temp += a[i];
            back = max(back, temp);
            ans = max(ans, back + dp[i]);
            temp = max(0, temp);
        }
        printf("%d\n", ans);
    }

    return 0;
}

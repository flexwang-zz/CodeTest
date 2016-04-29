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

//#define POJ_1692
#ifdef  POJ_1692
#include <stdio.h>
#include <algorithm>
#include <string.h>

using std::max;

const int   max_n = 105;
int         n1, n2;
int         a[max_n], b[max_n];
int         dp[max_n][max_n];

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--) {
        scanf("%d%d", &n1, &n2);
        for (int i=0; i<n1; i++)
            scanf("%d", &a[i]);
        for (int i=0; i<n2; i++)
            scanf("%d", &b[i]);
        memset(dp, 0, sizeof(dp));
        for (int i=2; i<=n1; i++)
            for (int j=2; j<=n2; j++) {
                dp[i][j] = max(dp[i-1][j-1],max(dp[i-1][j], dp[i][j-1]));
                if (a[i-1]!=b[j-1]) {
                    int k1, k2;
                    for (k1=j-2; k1>=0&&b[k1]!=a[i-1]; k1--);
                    for (k2=i-2; k2>=0&&a[k2]!=b[j-1]; k2--);
                    if (k1 >=0 && k2>=0)
                        dp[i][j] = max(dp[i][j], dp[k2][k1]+2);
                }
                    
            }
        printf("%d\n", dp[n1][n2]);
    }

    return 0;
}

#endif
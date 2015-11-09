//#define POJ_1836
#ifdef  POJ_1836
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int       max_n = 1001;
int             n;
float           h[max_n];
int             dp[max_n];

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%f", &h[i]);
    }
    int ans = INT_MAX;
    for (int i=0; i<n; i++) {
        int local_ans = 0;
        int d = 1;
        memset(dp, 0, sizeof(dp));
        dp[i] = 1;
        for (int j=i-1; j>=0; j--) {
            for (int k=j+1; k<=i; k++)
                if (h[k] < h[i] || k==i) {
                    if (h[j] < h[k])
                        dp[
                }

        }
        ans = min(ans, local_ans);
    }
    printf("%d\n", ans);
    return 0;
}

#endif
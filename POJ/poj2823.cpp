#include <stdio.h>
#include <limits.h>

#define     max_n 1000001
int         que1[max_n], que2[max_n];
int         a[max_n];
int         ans1[max_n], ans2[max_n];
int         n, k;
int         s1, s2, t1, t2;

int search1(int l, int r, int *que, int ai)
{
    while (l+1 < r) {
        int m = (l+r)/2;
        if (a[que[m]] <= ai)
            l = m;
        else
            r = m;
    }
    return l;
}

int search2(int l, int r, int *que, int ai)
{
    while (l+1 < r) {
        int m = (l+r)/2;
        if (a[que[m]] >= ai)
            l = m;
        else
            r = m;
    }
    return l;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) 
        scanf("%d", &a[i]);
    for (int i=0; i<n; i++) {
        while (s1 < t1 && a[que1[t1-1]] > a[i])
            t1--;
        while (s2 < t2 && a[que2[t2-1]] < a[i])
            t2 --;
        que1[t1++] = i;
        que2[t2++] = i;
        if (i >= k-1) {
            ans1[i-k+1] = a[que1[s1]];
            ans2[i-k+1] = a[que2[s2]];
            if (que1[s1] == i-k+1) s1++;
            if (que2[s2] == i-k+1) s2++;
        }
    }
    for (int i=0; i<n-k+1; i++)
        printf("%d%c", ans1[i], i==n-k?'\n':' ');
    for (int i=0; i<n-k+1; i++)
        printf("%d%c", ans2[i], i==n-k?'\n':' ');
    return 0;
}

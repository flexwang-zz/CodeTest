/*
Description

N (2 <= N <= 8,000) cows have unique brands in the range 1..N. In a spectacular display of poor judgment, they visited the neighborhood 'watering hole' and drank a few too many beers before dinner. When it was time to line up for their evening meal, they did not line up in the required ascending numerical order of their brands. 

Regrettably, FJ does not have a way to sort them. Furthermore, he's not very good at observing problems. Instead of writing down each cow's brand, he determined a rather silly statistic: For each cow in line, he knows the number of cows that precede that cow in line that do, in fact, have smaller brands than that cow. 

Given this data, tell FJ the exact ordering of the cows. 
Input

* Line 1: A single integer, N 

* Lines 2..N: These N-1 lines describe the number of cows that precede a given cow in line and have brands smaller than that cow. Of course, no cows precede the first cow in line, so she is not listed. Line 2 of the input describes the number of preceding cows whose brands are smaller than the cow in slot #2; line 3 describes the number of preceding cows whose brands are smaller than the cow in slot #3; and so on. 
Output

* Lines 1..N: Each of the N lines of output tells the brand of a cow in line. Line #1 of the output tells the brand of the first cow in line; line 2 tells the brand of the second cow; and so on.
Sample Input

5
1
2
1
0
Sample Output

2
4
5
3
1
*/

#include <stdio.h>

using namespace std;

const int max_n = 10000;

int     dat[max_n*2];
int     len;
int     n;
int     pre[max_n], ans[max_n];

void    init() {
    len = 1;
    while (len < n)
        len *= 2;

    for (int i=0; i<n; i++)
        dat[i+len-1] = 1;
    for (int i=len-2; i>=0; i--)
        dat[i] = dat[i*2+1]+dat[i*2+2];
}

void    update(int k, int x) {
    k = k + len - 1;
    dat[k] = x;
    while (k) {
        k = (k-1)/2;
        dat[k] = dat[k*2+1] + dat[k*2+2];
    }
}

int     query(int l, int r, int k, int left, int right) {

    if (l >= right || r <= left)    return 0;
    if (l <= left && r >= right)    return dat[k];
    return query(l, r, k*2+1, left, (left+right)/2)
        + query(l, r, k*2+2, (left+right)/2, right);
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<n; i++)
        scanf("%d", &pre[i]);
    init();
    
    for (int i=n-1; i>=0; i--) {
        int l = 0, r = n+1;
        while (l+1 < r) {
            int m = (l+r) / 2;
            int t = query(0, m, 0, 0, len);
            if (t <= pre[i]) {
                l = m;
            }
            else
                r = m;
        }
        ans[i] = l + 1;
        update(l, 0);
    }

    for (int i=0; i<n; i++)
        printf("%d\n", ans[i]);
    return 0;
}

/*
Description

You have N integers, A1, A2, ... , AN. You need to deal with two kinds of operations. One type of operation is to add some given number to each number in a given interval. The other is to ask for the sum of numbers in a given interval.

Input

The first line contains two numbers N and Q. 1 ¡Ü N,Q ¡Ü 100000.
The second line contains N numbers, the initial values of A1, A2, ... , AN. -1000000000 ¡Ü Ai ¡Ü 1000000000.
Each of the next Q lines represents an operation.
"C a b c" means adding c to each of Aa, Aa+1, ... , Ab. -10000 ¡Ü c ¡Ü 10000.
"Q a b" means querying the sum of Aa, Aa+1, ... , Ab.

Output

You need to answer all Q commands in order. One answer in a line.

Sample Input

10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
Sample Output

4
55
9
15
Hint

The sums may exceed the range of 32-bit integers.
*/

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

typedef long long ll;

const int max_n = 200000;

ll      data[max_n*2], datb[max_n*2];
int     n, q;

void    add(int a, int b, int x, int k, int l, int r)
{
    if (a <= l && r <= b)   data[k] += x;
    else if (a < r && b > l) {
        datb[k] += (min(b, r) - max(a, l))*x;
        add(a, b, x, k*2+1, l, (l+r)/2);
        add(a, b, x, k*2+2, (l+r)/2, r);
    }
}

ll     sum(int a, int b, int k, int l, int r)
{
    if (a <= l && r <= b)   return (r-l)*data[k]+datb[k];
    else if (a < r && b > l) {
        return data[k] * (min(b, r) - max(a, l))
            + sum(a, b, k*2+1, l, (l+r)/2)
            + sum(a, b, k*2+2, (l+r)/2, r);
    }
    return  0;
}


int main()
{
    scanf("%d %d", &n, &q);
    
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        add(i, i+1, x, 0, 0, n);
    }

    for (int i=0; i<q; i++) {
        char cmd[3];
        scanf("%s", cmd);

        if (!strcmp(cmd, "C")) {
            int a, b, x;
            scanf("%d %d %d", &a, &b, &x);
            add(a-1, b, x, 0, 0, n);
        }
        else {
            int a, b;
            scanf("%d %d", &a, &b);
            ll s = sum(a-1, b, 0, 0, n);
            printf("%lld\n", s);
        }
    }

    return 0;
}

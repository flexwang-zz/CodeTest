#define POJ_3253
#ifdef POJ_3253
#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

int         n;
vector<ll>  ls;


int main()
{
    ll ans = 0ll;

    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        ll l;
        scanf("%lld", &l);
        ls.push_back(l);
    }

    while (n > 1) {

        int min1 = 0, min2 = 1;

        if (ls[min1] > ls[min2])    swap(min1, min2);

        for (int i=2; i<n; i++) 
            if (ls[i] < ls[min1]) {
                min2 = min1;
                min1 = i;
            }
            else if (ls[i] < ls[min2])
                min2 = i;

        ll t = ls[min1] + ls[min2];
        ans += t;

        if (min1 == n-1)    swap(min1, min2);

        ls[min1] = t;
        ls[min2] = ls[n-1];

        n --;   
    }

    printf("%lld\n", ans);

    return 0;

}

#endif
#define POJ_3069
#ifdef POJ_3069

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int         n, r;
vector<int> xs;

int main()
{
    for (;;) {
        scanf("%d %d", &r, &n);
        if (n < 0)  break;
        xs.clear();
        for (int i=0; i<n; i++) {
            int x;
            scanf("%d", &x);
            xs.push_back(x);
        }

        sort(&xs[0], &xs[0]+n);

        int ans = 0;

        int left = xs[0];
        int x0 = 0;
        while (true) {
            for (;x0+1<n && xs[x0+1]-left<=r; x0++);
            ans ++;
            left = xs[x0];
            if (x0 == n-1)    break;
            for (;x0+1<n && xs[x0+1]-left<=r; x0++);
            if (x0 == n-1)    break;
            x0++;
            left = xs[x0];
        }

        printf("%d\n", ans);
    }
}

#endif
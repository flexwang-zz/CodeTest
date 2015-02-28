/*
As the manager of your company, you have to carefully consider, for each project, the time taken to finish it, the deadline, and the profit you can gain, in order to decide if your group should take this project. For example, given 3 projects as the following:

Project[1] takes 3 days, it must be finished in 3 days in order to gain 6 units of profit.
Project[2] takes 2 days, it must be finished in 2 days in order to gain 3 units of profit.
Project[3] takes 1 day only, it must be finished in 3 days in order to gain 4 units of profit.
You may take Project[1] to gain 6 units of profit. But if you take Project[2] first, then you will have 1 day left to complete Project[3] just in time, and hence gain 7 units of profit in total. Notice that once you decide to work on a project, you have to do it from beginning to the end without any interruption.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N(<=50), and then followed by N lines of projects, each contains three numbers P, L, and D where P is the profit, L the lasting days of the project, and D the deadline. It is guaranteed that L is never more than D, and all the numbers are non-negative integers.

Output Specification:

For each test case, output in a line the maximum profit you can gain.

Sample Input:
4
7 1 3
10 2 3
6 1 2
5 1 1
Sample Output:
18
*/

#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Project{
    ll p, l, d;
    bool operator <(const Project& pp) const {
        return d < pp.d;
    }
};

const int   max_n = 55;
Project     p[max_n];
int         n;
map<ll, ll> f[max_n+1];

int main()
{
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        scanf("%lld %lld %lld", &p[i].p, &p[i].l, &p[i].d);
    }

    sort(p, p+n);

    f[0][0] = 0;

    for (int i=0; i<n; i++) {
        f[i+1] = f[i];
        for (map<ll,ll>::iterator iter=f[i].begin(); iter!=f[i].end(); iter++) {
            ll d1 = iter->first + p[i].l;
            ll p1 = iter->second + p[i].p;
            
            if (d1 > p[i].d)  continue;
            f[i+1][d1] = max(f[i+1][d1], p1);
        }
    }

    ll ans = 0;

    for (map<ll,ll>::iterator iter=f[n].begin(); iter!=f[n].end(); iter++) 
        ans = max(ans, iter->second);

    printf("%lld", ans);

    return 0;
}
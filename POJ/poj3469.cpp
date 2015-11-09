//#define POJ_3469
#ifdef  POJ_3469
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <string.h>
using namespace std;
struct edge{
    int to, cap, rev;
    edge(int t, int c, int r):to(t), cap(c), rev(r){}
};

const int       max_n = 20005;
vector<edge>    G[max_n];
bool            used[max_n];
int             n, m, nv;

void add_edge(int from, int to, int cap)
{
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size()-1));
}
int dfs(int s, int t, int f)
{
    used[s] = true;
    if (s==t)   return f;
    for (int i=0; i<G[s].size(); i++) {
        edge &e = G[s][i];
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    int s = n;
    int t = s + 1;
    nv = t + 1;
    for (int i=0; i<n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add_edge(s, i, a);
        add_edge(i, t, b);
    }
    for (int i=0; i<m; i++) {
        int a, b, m;
        scanf("%d%d%d", &a, &b, &m);
        add_edge(a-1, b-1, m);
        add_edge(b-1, a-1, m);
    }

    int ans = 0;
    for (;;) {
        memset(used, false, sizeof(used));
        int d = dfs(s, t, INT_MAX);
        if (d == 0) break;
        ans += d;
    }
    printf("%d\n", ans);
    return 0;
}

#endif
/*
Description

Dearboy, a goods victualer, now comes to a big problem, and he needs your help. In his sale area there are N shopkeepers (marked from 1 to N) which stocks goods from him.Dearboy has M supply places (marked from 1 to M), each provides K different kinds of goods (marked from 1 to K). Once shopkeepers order goods, Dearboy should arrange which supply place provide how much amount of goods to shopkeepers to cut down the total cost of transport. 

It's known that the cost to transport one unit goods for different kinds from different supply places to different shopkeepers may be different. Given each supply places' storage of K kinds of goods, N shopkeepers' order of K kinds of goods and the cost to transport goods for different kinds from different supply places to different shopkeepers, you should tell how to arrange the goods supply to minimize the total cost of transport.
Input

The input consists of multiple test cases. The first line of each test case contains three integers N, M, K (0 < N, M, K < 50), which are described above. The next N lines give the shopkeepers' orders, with each line containing K integers (there integers are belong to [0, 3]), which represents the amount of goods each shopkeeper needs. The next M lines give the supply places' storage, with each line containing K integers (there integers are also belong to [0, 3]), which represents the amount of goods stored in that supply place. 

Then come K integer matrices (each with the size N * M), the integer (this integer is belong to (0, 100)) at the i-th row, j-th column in the k-th matrix represents the cost to transport one unit of k-th goods from the j-th supply place to the i-th shopkeeper. 

The input is terminated with three "0"s. This test case should not be processed.
Output

For each test case, if Dearboy can satisfy all the needs of all the shopkeepers, print in one line an integer, which is the minimum cost; otherwise just output "-1".
Sample Input

1 3 3   
1 1 1
0 1 1
1 2 2
1 0 1
1 2 3
1 1 1
2 1 1

1 1 1
3
2
20

0 0 0
Sample Output

4
-1
*/
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <limits.h>
#include <utility>
using namespace std;
typedef pair<int, int> P;
struct edge{
    int to, cap, dist, rev;
    edge(int t, int c, int d, int r):to(t), cap(c), dist(d), rev(r){}
};

const int       max_n = 105;
const int       max_k = 55;
vector<edge>    G[max_n];
int             prevv[max_n], preve[max_n];
int             h[max_n], dist[max_n];
int             nv;

int             need[max_k][max_k], has[max_k][max_k];
int             n, m, k;

void init()
{
    for (int i=0; i<max_n; i++)
        G[i].clear();
}

void add_edge(int from, int to, int cap, int dist)
{
    G[from].push_back(edge(to, cap, dist, G[to].size()));
    G[to].push_back(edge(from, 0, -dist, G[from].size()-1));
}

int min_cost_flow(int s, int t, int f)
{
    fill(h, h+nv, 0);
    int ans = 0;
    while (f>0) {
        fill(dist, dist+nv, INT_MAX);
        priority_queue<P, vector<P>, greater<P> > que;
        dist[s] = 0;
        que.push(P(0, s));
        while (!que.empty()) {
            P p = que.top(); que.pop();
            int v = p.second;
            if (dist[v] < p.first)  continue;
            for (int i=0; i<G[v].size(); i++) {
                edge& e = G[v][i];
                if (e.cap>0 && dist[e.to] > dist[v]+e.dist+h[v]-h[e.to]) {
                    dist[e.to] = dist[v]+e.dist+h[v]-h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }
        if (dist[t] == INT_MAX) return -1;
        for (int v=0; v<nv; v++)
            h[v] += dist[v];
        int d = f;
        for (int v=t; v!=s; v=prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);
        for (int v=t; v!=s; v=prevv[v]) {
            edge& e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[e.to][e.rev].cap += d;
        }
        ans += d*h[t];
        f -= d;
    }
    return ans;
}

void solve()
{
    for (int i=0; i<n; i++)
        for (int j=0; j<k; j++)
            scanf("%d", &need[i][j]);
    for (int i=0; i<m; i++)
        for (int j=0; j<k; j++)
            scanf("%d", &has[i][j]);
    int s = n+m; int t = s+1;
    nv = t+1;
    int ans = 0;
    for (int kk=0; kk<k; kk++) {
        init();
        int f = 0;
        for (int i=0; i<n; i++) {
            add_edge(s, i, need[i][kk], 0);
            f += need[i][kk];
        }
        for (int i=0; i<m; i++)
            add_edge(n+i, t, has[i][kk], 0);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                int fee;
                scanf("%d", &fee);
                add_edge(i, n+j, INT_MAX, fee);
            }
        int mfc = min_cost_flow(s, t, f);
        if (mfc >= 0 && ans >= 0)
            ans += mfc;
        else {
            ans = -1;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    for (;;) {
        scanf("%d%d%d", &n, &m, &k);
        if (!n) break;
        solve();
    }
    return 0;
}
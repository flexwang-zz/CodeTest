/*
Description

The Windy's is a world famous toy factory that owns M top-class workshop to make toys. This year the manager receives N orders for toys. The manager knows that every order will take different amount of hours in different workshops. More precisely, the i-th order will take Zij hours if the toys are making in the j-th workshop. Moreover, each order's work must be wholly completed in the same workshop. And a workshop can not switch to another order until it has finished the previous one. The switch does not cost any time.

The manager wants to minimize the average of the finishing time of the N orders. Can you help him?

Input

The first line of input is the number of test case. The first line of each test case contains two integers, N and M (1 ¡Ü N,M ¡Ü 50).
The next N lines each contain M integers, describing the matrix Zij (1 ¡Ü Zij ¡Ü 100,000) There is a blank line before each test case.

Output

For each test case output the answer on a single line. The result should be rounded to six decimal places.

Sample Input

3

3 4
100 100 100 1
99 99 99 1
98 98 98 1

3 4
1 100 100 100
99 1 99 99
98 98 1 98

3 4
1 100 100 100
1 99 99 99
98 1 98 98
Sample Output

2.000000
1.000000
1.333333
*/

#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
#include <limits.h>

using namespace std;

typedef pair<int, int> P;

struct edge{
    int to, dist, cap, rev;
    edge(int t, int d, int c, int r):to(t), dist(d), cap(c), rev(r){}
};

const int       max_v = 3000;
const int       max_n = 52;
const int       max_m = 52;
int             n, m, nv;
int             z[max_n][max_m];
vector<edge>    G[max_v];
int             prevv[max_v], preve[max_v];
int             dist[max_v], h[max_v];

void init()
{
    for (int i=0; i<max_v; i++)
        G[i].clear();
}

void add_edge(int s, int t, int d, int c)
{
    G[s].push_back(edge(t, d, c, G[t].size()));
    G[t].push_back(edge(s, -d, 0, G[s].size()-1));
}

int min_cost_flow(int s, int t, int f)
{
    fill(h, h+nv, 0);

    int ans = 0;

    while (f > 0) {
        fill(dist, dist+nv, INT_MAX);

        dist[s] = 0;

        priority_queue<P, vector<P>, greater<P> > que;

        que.push(P(0, s));

        while (!que.empty()) {
            P p = que.top();
            que.pop();
            
            int v = p.second;

            if (dist[v] < p.first)  continue;

            for (int i=0; i<G[v].size(); i++) {
                edge &e = G[v][i];

                if (e.cap > 0 && dist[e.to] > dist[v]+e.dist+h[v]-h[e.to]) {
                    dist[e.to] = dist[v]+e.dist+h[v]-h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }

        if (dist[t] == INT_MAX) return -1;

        for (int i=0; i<nv; i++)
            h[i] += dist[i];

        int d = f;

        for (int v=t; v!=s; v=prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);

        f -= d;
        ans += h[t] * d;

        for (int v=t; v!=s; v=prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[e.to][e.rev].cap += d;
        }
    }

    return ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int ic=0; ic<ncase; ic++) {
        init();
        scanf("%d %d", &n, &m);
        int s = n+n*m;
        int t = s + 1;
        nv = t + 1;

        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++) 
                scanf("%d", &z[i][j]);

        for (int i=0; i<n; i++)
            add_edge(s, i, 0, 1);

        for (int j=0; j<m; j++)
            for (int i=0; i<n; i++) {
                add_edge(n+j*n+i, t, 0, 1);
                for (int k=0; k<n; k++)
                    add_edge(k, n+j*n+i, z[k][j]*(i+1), 1);
            }

        printf("%.6f\n", (double)min_cost_flow(s, t, n)/n);

    }

    return 0;
}
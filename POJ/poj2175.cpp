//#define POJ_2175
#ifdef  POJ_2175

#include <stdio.h>
#include <vector>
#include <functional>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

typedef pair<int, int> P;

const int max_n = 500;

struct edge{
    int to, dist, cap, rev;
    edge(int t, int d, int c, int r):to(t), dist(d), cap(c), rev(r){}
}; 

int             n, nb, f, ns;
vector<edge>    G[max_n];
int             x[max_n], y[max_n], cap[max_n];
int             h[max_n], dist[max_n];
int             prevv[max_n], preve[max_n];

void add_edge(int from, int to, int dist, int cap)
{
    G[from].push_back(edge(to, dist, cap, G[to].size()));
    G[to].push_back(edge(from, -dist, 0, G[from].size()-1));
}

int min_cost_flow(int s, int t, int f)
{
    int ans = 0;
    fill(h, h+n, 0);

    while (f > 0) {
        fill(dist, dist+n, INT_MAX);
        priority_queue<P, vector<P>, greater<P> > que;
        dist[s] = 0;
        que.push(P(0, s));

        while (!que.empty()) {
            P p = que.top();
            que.pop();

            int v = p.second;
            if (p.first > dist[v]) continue;

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

        for (int i=0; i<n; i++)
            h[i] += dist[i];

        int d = f;

        for (int v=t; v!=s; v=prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);

        ans += d*h[t];
        f -= d;

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
    scanf("%d %d", &nb, &ns);
    n = nb+ns+2;
    int s = nb+ns;
    int t = s+1;

    for (int i=0; i<nb+ns; i++) {
        scanf("%d %d %d", &x[i], &y[i], &cap[i]);
        if (i < nb) f += cap[i];
    }

    int cost = 0;

    for (int i=0; i<nb; i++)
        for (int j=0; j<ns; j++) {
            int e;
            scanf("%d", &e);
            int d = abs(x[i]-x[j+nb])+abs(y[i]-y[j+nb])+1;
            cost += e*d;
            add_edge(i, j+nb, d, INT_MAX);
        }

    for (int i=0; i<nb; i++) 
        add_edge(s, i, 0, cap[i]);
    for (int i=0; i<ns; i++)
        add_edge(nb+i, t, 0, cap[nb+i]);

    if (min_cost_flow(s, t, f) == cost) {
        printf("OPTIMAL\n");
    }
    else {
        printf("SUBOPTIMAL\n");
        for (int i=0; i<nb; i++)
            for (int j=0; j<ns; j++) 
                printf("%d%c", G[j+nb][i].cap, j==ns-1?'\n':' ');
    }

    return 0;
}

#endif
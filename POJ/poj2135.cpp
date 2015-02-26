/*
Description

When FJ's friends visit him on the farm, he likes to show them around. His farm comprises N (1 <= N <= 1000) fields numbered 1..N, the first of which contains his house and the Nth of which contains the big barn. A total M (1 <= M <= 10000) paths that connect the fields in various ways. Each path connects two different fields and has a nonzero length smaller than 35,000. 

To show off his farm in the best way, he walks a tour that starts at his house, potentially travels through some fields, and ends at the barn. Later, he returns (potentially through some fields) back to his house again. 

He wants his tour to be as short as possible, however he doesn't want to walk on any given path more than once. Calculate the shortest tour possible. FJ is sure that some tour exists for any given farm.
Input

* Line 1: Two space-separated integers: N and M. 

* Lines 2..M+1: Three space-separated integers that define a path: The starting field, the end field, and the path's length. 
Output

A single line containing the length of the shortest tour. 
Sample Input

4 5
1 2 1
2 3 1
3 4 1
1 3 2
2 4 2
Sample Output

6
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>
#include <limits.h>

using namespace std;

typedef pair<int, int> P;

const int max_n = 1000;

struct edge
{
    int to, dist, cap, rev;
    edge(int t, int d, int c, int r):to(t), dist(d), cap(c), rev(r){}
};

vector<edge>    G[max_n];
int             h[max_n], dist[max_n];
int             prevv[max_n], preve[max_n];
int             n;

void add_edge(int from, int to, int dist)
{
    G[from].push_back(edge(to, dist, 1, G[to].size()));
    G[to].push_back(edge(from, -dist, 0, G[from].size()-1));
}

int min_cost_flow(int s, int t, int f) {
    int ans = 0;
	
    fill(h, h+n, 0);
	
    while (f > 0) {
        priority_queue<P, vector<P>, greater<P> > que;
        fill(dist, dist+n, INT_MAX);

        dist[s] = 0;
        que.push(P(0, s));

        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (p.first > dist[v]) continue;
            
            for (int i=0; i<G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v]+h[v]-h[e.to]+e.dist) {
                    dist[e.to] = dist[v]+h[v]-h[e.to]+e.dist;
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }

        if (dist[t] == INT_MAX)
            return -1;
        for (int i=0; i<n; i++)
            h[i] += dist[i];

        int d = f;
        for (int i=t; i!=s; i=prevv[i])
            d = min(G[prevv[i]][preve[i]].cap, d);
        f -= d;
        ans += d * h[t];

        for (int i=t; i!=s; i=prevv[i]) {
            edge &e = G[prevv[i]][preve[i]];
            e.cap -= d;
            G[e.to][e.rev].cap += d;
        }
    }

    return ans;
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);

    for (int i=0; i<m; i++) {
        int a, b, dist;
        scanf("%d %d %d", &a, &b, &dist);
        a--;
        b--;
        add_edge(a, b, dist);
        add_edge(b, a, dist);
    }
    int s = 0, t = n-1;
    printf("%d", min_cost_flow(s, t, 2));

    return 0;
}
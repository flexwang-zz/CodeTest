/*
Input our current position and a destination, an online map can recommend several paths. Now your job is to recommend two paths to your user: one is the shortest, and the other is the fastest. It is guaranteed that a path exists for any request.

Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers N (2 <= N <= 500), and M, being the total number of streets intersections on a map, and the number of streets, respectively. Then M lines follow, each describes a street in the format:

V1 V2 one-way length time

where V1 and V2 are the indices (from 0 to N-1) of the two ends of the street; one-way is 1 if the street is one-way from V1 to V2, or 0 if not; length is the length of the street; and time is the time taken to pass the street.

Finally a pair of source and destination is given.

Output Specification:

For each case, first print the shortest path from the source to the destination with distance D in the format:

Distance = D: source -> v1 -> ... -> destination

Then in the next line print the fastest path with total time T:

Time = T: source -> w1 -> ... -> destination

In case the shortest path is not unique, output the fastest one among the shortest paths, which is guaranteed to be unique. In case the fastest path is not unique, output the one that passes through the fewest intersections, which is guaranteed to be unique.

In case the shortest and the fastest paths are identical, print them in one line in the format:

Distance = D; Time = T: source -> u1 -> ... -> destination

Sample Input 1:
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5
Sample Output 1:
Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5
Sample Input 2:
7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5
Sample Output 2:
Distance = 3; Time = 4: 3 -> 2 -> 5
*/

#include <vector>
#include <stdio.h>
#include <algorithm>
#include <limits.h>

using namespace std;

struct edge{
    int to, l, t;
};

const int max_n =501;
vector<edge> G[max_n];
int n, m;
int s, t;
vector<int> p1, p2;

int d1()
{
    vector<bool> known(n, false);
    vector<int> cost(n, INT_MAX);
    vector<int> time(n, INT_MAX);
    vector<int> last(n, -1);
    cost[s] = 0;
    for(;;) {
        int idx = -1;
        for (int i=0; i<n; ++i) {
            if (cost[i] == INT_MAX || known[i]) continue;
            if (idx == -1 || cost[idx] > cost[i])
                idx = i;
        }
        if (idx < 0) break;
        known[idx] = true;
        for (auto &e: G[idx]) {
            int to = e.to;
            if (known[to]) continue;
            if (cost[to] > cost[idx]+e.l
                || cost[to] == cost[idx]+e.l && time[to] > time[idx]+e.t) {
                cost[to] = cost[idx]+e.l;
                time[to] = time[idx]+e.t;
                last[to] = idx;
            }
        }
    }
    for (int i=t; i>=0; i=last[i])
        p1.push_back(i);
    return cost[t];
}

int d2()
{
    vector<bool> known(n, false);
    vector<int> cost(n, INT_MAX);
    vector<int> inter(n, 0);
    vector<int> last(n, -1);
    cost[s] = 0;
    for(;;) {
        int idx = -1;
        for (int i=0; i<n; ++i) {
            if (cost[i] == INT_MAX || known[i]) continue;
            if (idx == -1 || cost[idx] > cost[i])
                idx = i;
        }
        if (idx < 0) break;
        known[idx] = true;
        for (auto &e: G[idx]) {
            int to = e.to;
            if (known[to]) continue;
            if (cost[to] > cost[idx]+e.t
                || cost[to] == cost[idx]+e.t && inter[to] > inter[idx]+1) {
                cost[to] = cost[idx]+e.t;
                inter[to] = inter[idx]+1;
                last[to] = idx;
            }
        }
    }
    for (int i=t; i>=0; i=last[i])
        p2.push_back(i);
    return cost[t];
}

void print_path(const vector<int>& p) {
    for (int i=p.size()-1; i>=0; --i)
        printf("%d%s", p[i], i?" -> ":"\n");
}


int main()
{
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; ++i) {
        int a, b, c, l, t;
        scanf("%d %d %d %d %d", &a, &b, &c, &l, &t);
        G[a].push_back({b, l, t});
        if (!c) G[b].push_back({a, l, t});
    }
    scanf("%d %d", &s, &t);
    int dist = d1();
    int time = d2();
    if (p1 == p2) {
        printf("Distance = %d; Time = %d: ", dist, time);
        print_path(p1);
    }
    else {
        printf("Distance = %d: ", dist);
        print_path(p1);
        printf("Time = %d: ", time);
        print_path(p2);
    }

    return 0;
}
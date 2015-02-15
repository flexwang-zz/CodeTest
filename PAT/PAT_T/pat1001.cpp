/*
It is vitally important to have all the cities connected by highways in a war. If a city is conquered by the enemy, all the highways from/toward that city will be closed. To keep the rest of the cities connected, we must repair some highways with the minimum cost. On the other hand, if losing a city will cost us too much to rebuild the connection, we must pay more attention to that city.

Given the map of cities which have all the destroyed and remaining highways marked, you are supposed to point out the city to which we must pay the most attention.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 2 numbers N (<=500), and M, which are the total number of cities, and the number of highways, respectively. Then M lines follow, each describes a highway by 4 integers:

City1 City2 Cost Status
where City1 and City2 are the numbers of the cities the highway connects (the cities are numbered from 1 to N), Cost is the effort taken to repair that highway if necessary, and Status is either 0, meaning that highway is destroyed, or 1, meaning that highway is in use.

Note: It is guaranteed that the whole country was connected before the war.

Output Specification:

For each test case, just print in a line the city we must protest the most, that is, it will take us the maximum effort to rebuild the connection if that city is conquered by the enemy.

In case there is more than one city to be printed, output them in increasing order of the city numbers, separated by one space, but no extra space at the end of the line. In case there is no need to repair any highway at all, simply output 0.

Sample Input 1:
4 5
1 2 1 1
1 3 1 1
2 3 1 0
2 4 1 1
3 4 1 0
Sample Output 1:
1 2
Sample Input 2:
4 5
1 2 1 1
1 3 1 1
2 3 1 0
2 4 1 1
3 4 2 1
Sample Output 2:
0
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct edge{
    int from, to, cost;
    edge(int f, int t, int c):from(f), to(t), cost(c){}
    bool operator<(const edge& e) const {
        return cost < e.cost;
    }
};

int         n, m;

vector<int>         par;
vector<int>         depth;
vector<int>         result;
int                 k;
vector<edge>        edges1, edges2;
int                 max_cost;

void init()
{
    par.resize(n);
    for (int i=0; i<n; i++)
        par[i] = i;
    depth.assign(n, 0);
    k = n;
}

int find(int x) {
    if (par[x] == x)
        return x;
    
    return par[x] = find(par[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    k --;

    if (depth[x] > depth[y]) {
        par[y] = x;
    }
    else {
        par[x] = y;
        if (depth[x] == depth[y])
            depth[y] ++;
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    result.resize(n);

    for (int i=0; i<m; i++) {
        int from, to, cost, flag;
        scanf("%d %d %d %d", &from, &to, &cost, &flag);
        from --;
        to --;
        if (flag)
            edges1.push_back(edge(from, to, cost));
        else
            edges2.push_back(edge(from, to, cost));
    }

    sort(edges2.begin(), edges2.end());

    for (int target=0; target<n; target++) {
        init();
        for (int i=0; i<edges1.size(); i++) {
            const edge& e=edges1[i];
            if (e.from != target && e.to != target)
                merge(e.from, e.to);
        }

        result[target] = 0;
        for (int i=0; i<edges2.size() && k > 2; i++) {
            const edge& e=edges2[i];
            if (e.from != target && e.to != target 
                && !same(e.from, e.to)) {
                merge(e.from, e.to);
                result[target] += e.cost;
            }
        }

        if (k > 2) {
            result[target] = INT_MAX;
        }
        max_cost = max(max_cost, result[target]);
    }

    if (max_cost == 0)
        printf("0");
    else {
        vector<int> ans;
        for (int i=0; i<result.size(); i++)
            if (max_cost == result[i])
                ans.push_back(i+1);

        for (int i=0; i<ans.size(); i++) {
            if (i)  printf(" ");
            printf("%d", ans[i]);
        }
    }

    return 0;
}

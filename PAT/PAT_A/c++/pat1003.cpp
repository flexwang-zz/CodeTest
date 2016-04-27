/*﻿As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.
Input
Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.
Output
For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.
Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

Sample Output
2 4
*/

#include <iostream>
#include <vector>

using namespace std;
struct edge{
    int to, time;
};

int main()
{
    int n, m, c1, c2;
    vector<vector<edge>> G;
    vector<int> nt;
    
    cin >> n >> m >> c1 >> c2;
    G.resize(n);
    nt.resize(n);
    for (int i=0; i<n; ++i)
        cin >> nt[i];
    for (int i=0; i<m; ++i) {
        int v, s, t;
        cin >> v >> s >> t;
        G[v].push_back({s, t});
        G[s].push_back({v, t});
    }

    vector<bool> used(n);
    vector<int> dist(n, 0x5fffffff), cost(n), np(n);
    dist[c1] = 0;
    cost[c1] = nt[c1];
    np[c1] = 1;
    for (;;) {
        int idx = -1;
        for (int i=0; i<n; ++i) 
            if (!used[i] && (idx < 0 || dist[idx] > dist[i]))
                idx = i;
        if (idx < 0) break;
        used[idx] = true;
        for (auto &e : G[idx]) {
            int t = e.to;
            if (used[t]) continue;
            if (dist[t] > dist[idx] + e.time) {
                dist[t] = dist[idx]+e.time; 
                cost[t] = cost[idx]+nt[t];
                np[t] = np[idx];
            }
            else if (dist[t] == dist[idx] + e.time) {
                cost[t] = max(cost[t], cost[idx]+nt[t]);
                np[t] += np[idx];
            }
        }
    }
    cout << np[c2] << " " << cost[c2] << endl;
    return 0;
}
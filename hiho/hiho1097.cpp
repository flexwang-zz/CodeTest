#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> G(n, vector<int>(n, 0));
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> G[i][j];
    dist[0] = 0;
    pq.push(make_pair(0, 0));
    int ans = 0;
    while (!pq.empty()) {
        pair<int,int> p = pq.top();
         pq.pop();
        int id = p.second, d = p.first;
        if (visited[id]) continue;
        visited[id] = true;
        ans += d;
        for (int i=0; i<n; i++) {
            if (!visited[i] && G[id][i] < dist[i]) {
                dist[i] = G[id][i];
                pq.push(make_pair(dist[i], i));
            }
        }
    }
    cout << ans << endl;
    return 0;

}
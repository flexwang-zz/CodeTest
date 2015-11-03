#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int mod = 142857;

vector<vector<int>> G;
vector<int> indegree;
vector<int> subsize;
void add_edge(int a, int b){
    a--, b--;
    G[a].push_back(b);
    indegree[b]++;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    subsize.resize(n, 0);
    for (int i=0; i<k; i++) {
        int a;
        cin >> a;
        subsize[--a]++;
    }
    indegree.resize(n);
    G.resize(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
    }
    queue<int> q;
    for (int i=0; i<n; i++)
        if (!indegree[i]) q.push(i);
    while (!q.empty()) {
        int id = q.front();
        q.pop();
        for (auto v:G[id]) {
            subsize[v] = (subsize[v]+subsize[id])%mod;
            if (--indegree[v] == 0) q.push(v);
        }
    }
    int sum = 0;
    for (auto x:subsize)
        sum = (sum+x)%mod;
    cout << sum << endl;
    return 0;
}
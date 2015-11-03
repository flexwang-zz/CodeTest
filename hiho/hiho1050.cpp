#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> G;

void add_edge(int a, int b) {
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
}

int dfs(int id, int p, int &ans) {
    int m1=0, m2=0;
    for (int i=0; i<G[id].size(); i++) {
        int v = G[id][i];
        if (v == p) continue;
        int d = dfs(v, id, ans);
        if (d >= m1) {
            m2 = m1;
            m1 = d;
        }
        else if (d > m2) m2 = d;
    }
    ans = max(ans, m1+m2+1);
    return m1+1;
}

int main()
{
    int n;
    cin >> n;
    G.resize(n);
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
    }
    int root = 0;
    int ans = 0;
    dfs(root, -1, ans);
    cout << --ans << endl;
    return 0;
}
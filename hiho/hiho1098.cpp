#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct E{
    int s, t, w;
};
bool operator<(const E&e1, const E&e2) {
    return e1.w<e2.w;
}

void init(vector<int>&v, int n) {
    v.resize(n);
    for (int i=0; i<n; i++)
        v[i] = i;
}

int find(int id, vector<int>& v) {
    if (id == v[id]) return id;
    return v[id] = find(v[id], v);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<E> es;
    for (int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        es.push_back({a-1, b-1, w});
    }
    sort(es.begin(), es.end());
    vector<int> v;
    init(v, n);
    int ans = 0;
    for (int i=0; i<es.size(); i++) {
        int a=es[i].s, b=es[i].t;
        a = find(a, v), b = find(b, v);
        if (a != b) {
            ans += es[i].w;
            v[a] = b;
        }
    }
    cout << ans << endl;
    return 0;
}
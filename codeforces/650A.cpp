#include <bits/stdc++.h> 

using namespace std;
typedef long long ll;

ll c2(ll n) {
    return n*(n-1)/2;
}
int main()
{
    int n;
    unordered_map<ll, ll> xm, ym;
    map<pair<ll, ll>, ll> m;
    cin >> n;
    for (int i=0; i<n; ++i) {
        ll x, y;
        cin >> x >> y;
        xm[x] ++;
        ym[y] ++;
        m[make_pair(x, y)] ++;
    }
    ll res = 0;
    for (auto x:xm)
        res += c2(x.second);
    for (auto y:ym)
        res += c2(y.second);
    for (auto x:m)
        res -= c2(x.second);
    cout << res << endl;
    return 0;
}

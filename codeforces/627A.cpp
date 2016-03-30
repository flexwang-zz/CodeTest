//http://codeforces.com/problemset/problem/627/A

#include <iostream>

using namespace std;

typedef long long ll;

ll get_bit(ll a, ll idx) {
    return a & (1ll<<idx);
}

const int max_n = 64;

int main()
{
    ll s, x;
    cin >> s >> x;
    ll a[max_n], b[max_n];
    a[0] = 1;
    b[0] = 0;
    for (int i=1; i<max_n; ++i) {
        ll sb = get_bit(s, i-1);
        ll xb = get_bit(x, i-1);
        if (sb && xb) {
            a[i] = 2*a[i-1];
            b[i] = 0;
        }
        else if (!sb && xb) {
            a[i] = 0;
            b[i] = 2*b[i-1];
        }
        else if (sb && !xb) {
            a[i] = b[i-1];
            b[i] = b[i-1];
        }
        else {
            b[i] = a[i-1];
            a[i] = a[i-1];
        }
    } 
    if (s == x) a[max_n-1] -= 2;
    cout << a[max_n-1] << endl;
    return 0;
}
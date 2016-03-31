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
    ll a = 1, b = 0;
    for (int i=1; i<max_n; ++i) {
        ll sb = get_bit(s, i-1);
        ll xb = get_bit(x, i-1);
        if (sb && xb) {
            a *= 2;
            b = 0;
        }
        else if (!sb && xb) {
            a = 0;
            b *= 2;
        }
        else if (sb && !xb) {
            a = b;
            b = b;
        }
        else {
            b = a;
            a = a;
        }
    } 
    if (s == x) a -= 2;
    cout << a << endl;
    return 0;
}
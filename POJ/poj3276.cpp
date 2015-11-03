#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

int get_turn(vector<bool> v, int k) {
    int n = v.size();
    vector<bool> turned(n, false);
    int nturn = 0;
    int ans = 0;
    for (int i=0; i+k<=n; i++) {
        if (i-k>=0 && turned[i-k]) nturn--;
        if (nturn%2) v[i] = !v[i];
        if (!v[i]) {
            ans ++;
            nturn ++;
            turned[i] = true;
        }
    }
    for (int i=n-k+1; i<n; i++) {
        if (i-k>=0 && turned[i-k]) nturn--;
        if (nturn%2) v[i] = !v[i];
        if (!v[i]) return INT_MAX;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<bool> v(n);
    for (int i=0; i<n; i++) {
        string t;
        cin >> t;
        v[i] = t=="F"?true:false;
    }

    int ans = n+1, k;
    for (int i=1; i<=n; i++) {
        int cur = get_turn(v, i);
        if (cur < ans) {
            ans = cur;
            k = i;
        }
    }
    cout << k << " " << ans<<endl;
    return 0;

}
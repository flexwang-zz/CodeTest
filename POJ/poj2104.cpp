#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void init_segment(vector<vector<int> > &seg, vector<int>& v, int id, int l, int r) {
    if (l+1 == r) {
        seg[id].push_back(v[l]);
        return;
    }
    int m = l+(r-l)/2;
    init_segment(seg, v, id*2+1, l, m);
    init_segment(seg, v, id*2+2, m, r);
    seg[id].resize(r-l);
    merge(seg[id*2+1].begin(), seg[id*2+1].end(), seg[id*2+2].begin(), seg[id*2+2].end(), seg[id].begin());
}

int get_cnt(vector<vector<int> > &data, int id, int l, int r, int a, int b, int x) {
    if (b <= l || r <= a) return 0;
    if (a <= l && b >= r) return upper_bound(data[id].begin(), data[id].end(), x)-data[id].begin();
    else {
        int m = l+(r-l)/2;
        return get_cnt(data, id*2+1, l, m, a, b, x)
            + get_cnt(data, id*2+2, m, r, a, b, x);
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(n), sv;
    for (int i=0; i<v.size(); i++)
        scanf("%d", &v[i]);
    sv = v;
    sort(sv.begin(), sv.end());
    int size = n==1?1:(n*4-5);
    vector<vector<int> > data(size);
    init_segment(data, v, 0, 0, n);
    for (int i=0; i<m; i++) {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        a--;
        int l = 0, r = n-1;
        while (l < r) {
            int mid = l+(r-l)/2;
            if (get_cnt(data, 0, 0, n, a, b, sv[mid]) < k) l = mid+1;
            else r = mid;
        }
        printf("%d\n", sv[l]);
    }
    return 0;
}
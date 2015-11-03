#include <iostream>
#include <algorithm>
using namespace std;

struct P{
    long long x, y;
    P(){}
    P(int xx, int yy):x(xx), y(yy){}
    bool is_zero() const {return x==0 && y==0;}
};

P operator-(const P&p1, const P&p2) {
    return P(p1.x-p2.x, p1.y-p2.y);
}

long long operator*(const P&p1, const P&p2) {
    return p1.x*p2.x+p1.y*p2.y;
}
long long operator^(const P&p1, const P&p2) {
    return p1.x*p2.y - p1.y*p2.x;
}

bool parallel(const P&p1, const P&p2) {
    return (p1^p2) == 0;
}
int main()
{
    int ncase;
    cin >> ncase;
    while (ncase--) {
        P p[4], q[4], d[4];
        bool flag=true;
        for (int i=0; i<4; i++) {
            cin >> p[i].x >> p[i].y >> q[i].x >> q[i].y;
            d[i] = p[i]-q[i];
            if (d[i].is_zero()) flag = false;
        }
        if (flag) {
            int s1[2], s2[2];
            s1[0] = 0;
            s1[1] = 1;
            for (int i=2; i<4; i++) {
                if (parallel(d[0], d[i])) {
                    s1[1] = i;
                    break;
                }
            }
            if (s1[1] != 1) {
                if (s1[1] = 2) s2 = {1, 3};
                else s2 = {1, 2};
            }
            else {
                s2[0] = 2;
                s2[1] = 3;
            }

            if (!parallel(d[s1[0]], d[s1[1]]) 
                || !parallel(d[s2[0]], d[s2[1]])
                || d[s1[0]]*d[s2[0]])
                flag = false;
            if (flag) {
                if (parallel(p[s1[0]]-p[s1[1]], d[s1[1]])
                    || parallel(p[s2[0]]-p[s2[1]], d[s2[1]]))
                    flag = false;
            }
        }
        if (flag) cout << "YES";
        else cout << "NO";
        if (ncase) cout << endl;
        
    }
    return 0;
}


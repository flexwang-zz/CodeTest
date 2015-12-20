class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int l = 1, r = x;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (x/m < m) r = m;
            else l = m;
        }
        return l;
    } 
};
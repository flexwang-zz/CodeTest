class Solution {
public:
    double myPow(double x, int n) {
        int e = n<0?-n:n;
        double p = n<0?1.0/x:x;
        double ans = 1.0;
        for (int i=0; i<32; i++) {
            if (e&(1<<i)) ans *= p;
            p *= p;
        }
        return ans;
    }
};
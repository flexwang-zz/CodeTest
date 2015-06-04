class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        double p = x;
        int sign = 1;
        if (n < 0) {
            sign = -1;
            n = -n;
        }
        for (int i=0; (1<<i) <=n && i<=31; i++) {
            if ((1<<i)&n) {
                if (sign < 0)
                    ans /= p;
                else
                    ans *= p;
            }
            p *= p;
        }
        return ans;
    }
	
	double pow(double x,int n) {
		double ret = 1.0;
		while(n > 0) {
			if(n & 1) ret = ret * x;
			x = x * x;
			n >> = 1;
		}
		return ret;
	}
};

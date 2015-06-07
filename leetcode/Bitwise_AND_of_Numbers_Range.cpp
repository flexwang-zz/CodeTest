class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for (int i=31; i>=0; i--) {
            int t1 = m&(1<<i);
            int t2 = n&(1<<i);
            if (t1 != t2) break;
            if (t1) ans += t1;
        }
        return ans;
    }
};
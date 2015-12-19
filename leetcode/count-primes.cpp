class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<bool> flag(n, true);
        int ans = n-2;
        for (int i=2; i<sqrt(n)+1; i++) {
            if (flag[i]) {
                for (int j=2; j*i<n; j++)
                    if (flag[j*i]) {
                        flag[j*i] = false;
                        ans--;
                    }
            }
        }
        return ans;
    }
};
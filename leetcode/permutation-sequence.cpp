class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        string ans;
        vector<int> tab;
        vector<bool> used(n, false);
        int p = 1;
        tab.push_back(1);
        for (int i = 2; i <= n; i++) {
            p *= i - 1;
            tab.push_back(p);
        }
        
        for (int i = 0; i < n; i++) {
            int t = k / tab[n - i - 1];
            k %= tab[n - i - 1];
            int t2 = 0;
            int j = 0;
            for (j = 0; j < n; j++)
            if (!used[j] && t2++ == t)
                break;
            used[j] = true;
            ans += '1' + j;
        }
        return ans;
    }
};
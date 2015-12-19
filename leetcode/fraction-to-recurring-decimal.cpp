class Solution {
public:
    long long myabs(int n) {
        long long ans = n;
        return ans>=0?ans:-ans;
    }
    string fractionToDecimal(int numerator, int denominator) {
        int sign = 1;
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) sign = -1;
        long long n = myabs(numerator);
        long long d = myabs(denominator);
        string ans;
        ans += to_string(n/d);
        n %= d;
        if (n) ans += '.';
        unordered_map<long long, int> tab;
        while (n)  {
            if (tab.find(n) == tab.end()) {
                tab[n] = ans.length();
                ans += to_string(n*10/d);
                n = n*10%d;
            }
            else {
                int start = tab.find(n)->second;
                ans.insert(ans.begin()+start, '(');
                ans += ')';
                break;
            }
        }
        if (sign == -1 && ans != "0") ans = "-"+ans;
    
        return ans;
    }
};
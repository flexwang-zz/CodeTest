class Solution {
public:
    int reverse(int x) {
        int sign = x >= 0 ? 1 : -1;
        if (x < 0)  x = -x;

        vector<int> digits;

        do{
            digits.push_back(x % 10);
            x /= 10;
        } while (x>0);

        int ans = 0;

        for (int i = 0; i < digits.size(); i++) {
            if (ans != ans*10/10) return 0;
            ans = ans * 10 + digits[i];
            if (ans < 0) return 0;
        }

        return ans*sign;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int p1 = 0, p2 = x;
        while (p2 > 0) {
            p1 = p1*10 + p2%10;
            p2 /= 10;
        }
        return p1 == x;
    }
};
class Solution {
public:
    int nextNum(string &s, int &i) {
        int num = 0;
        for (;i<s.length(); i++)
            if (s[i] >='0' && s[i] <= '9')
                num = num*10 + s[i]-'0';
            else if (s[i] == ' ') continue;
            else break;
        return num;
    }
    int calculate(string s) {
        int i = 0;
        int result = 0;
        int cur = nextNum(s, i);
        char last_op = ' ';
        while (i != s.length()) {
            if (s[i] == '*') cur *= nextNum(s, ++i);
            else if (s[i] == '/') cur /= nextNum(s, ++i);
            else if (last_op == '+') result += cur, last_op=s[i], cur = nextNum(s, ++i);
            else if (last_op == '-') result -= cur, last_op=s[i], cur = nextNum(s, ++i);
            else result = cur, last_op = s[i], cur = nextNum(s, ++i);
        }
        if (last_op == ' ') return cur;
        else if (last_op == '+') return result+cur;
        else return result-cur;
    }
};

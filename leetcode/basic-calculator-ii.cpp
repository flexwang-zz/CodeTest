class Solution {
public:
    int calculate(string s) {
        stack<int> sd;
        stack<char> sr;
        s = '('+s;
        s += ')';
        int last_d = 0;
        bool last_n = false;
        for (int i=0; i<s.length(); i++) {
            char ch = s[i];
            if (ch == ' ') continue;
            if (!isoperator(ch)) {
                last_d = last_d*10 + ch-'0';
                last_n = true;
            }
            else {
                if (last_n)
                    sd.push(last_d);
                last_d = 0;
                last_n = false;
                while (!sr.empty() && diff(sr.top(), ch) < 0) {
                    char top = sr.top(); 
                    sr.pop();
                    if (top == '(' && ch == ')') break;
                    int b = sd.top();
                    sd.pop();
                    int a = sd.top();
                    sd.pop();
                    sd.push(calc(a, b, top));
                }
                if (ch != ')') sr.push(ch);
            }
        }
        return sd.top();
    }
    int calc(int a, int b, char op) {
        switch(op) {
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            case '/': return a/b;
        }
    }    
    bool isoperator(char ch) {
        return ch < '0' || ch > '9';
    }
    int diff(char p1, char p2) {
        if (p1 == '(') {
            if (p2 == ')') return -1;
            return 1;
        }
        if (p2 == '(')
            return 1;
        if (p2 == ')')
            return -1;
        if (p1 == '+' || p1 == '-') {
            if (p2 == '*' || p2 == '/') return 1;
            return -1;
        }
        if (p1 == '*' || p1 == '/') return -1;
    }
};
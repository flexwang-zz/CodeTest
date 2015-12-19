class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0; i<s.length(); i++) {
            char c = s[i];
            if (c=='(' || c=='[' || c=='{')
                st.push(c);
            else {
                if (st.empty()) return false;
                char c2 = st.top();
                st.pop();
                if (!(c2 == '(' && c==')' || c2=='[' && c==']' || c2=='{' && c=='}'))
                    return false;
            }
        }
        return st.empty();
    }
};
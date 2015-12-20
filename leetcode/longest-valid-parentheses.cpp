class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<int> len(s.length()+1, 0);
        
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty()) {
                    int idx = st.top();
                    st.pop();
                    len[i] = idx==0?i+1:len[idx-1]+i+1-idx;
                }
                else
                    len[i] = 0;
            }
        }
        
        int ans = 0;
        for (int i=0; i<len.size(); i++)
            ans = max(ans, len[i]);
        return ans;
        
    }
};
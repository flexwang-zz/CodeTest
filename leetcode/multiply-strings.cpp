class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        for (int i=0; i<num1.size(); i++) {
            if (ans != "0")
                ans = ans+'0';
            ans = add(ans, multiply(num2, num1[i]-'0'));
        }
        return ans;
    }
    
    string multiply(string num, int d) {
        if (d == 0) return "0";
        int len = num.size();
        string ans(len,'0');
        int c = 0;
        for (int i=num.size()-1; i>=0; i--) {
            int val = (num[i]-'0')*d+c;
            ans[i] = val%10 + '0';
            c = val/10;
        }
        if (c)
            ans = (char)(c+'0')+ans;
        return ans;
    }
    
    string add(string num1, string num2) {
        //if (num1 == "" || num1 == "0") return num2;
        int len = max(num1.size(), num2.size());
        string ans(len,'0');
        int p1 = num1.size()-1, p2 = num2.size()-1;
        int p3 = ans.size()-1;
        int c = 0;
        while (p1>=0 || p2>=0) {
            if (p1>=0 && p2>=0) {
                int val = num1[p1]-'0'+num2[p2]-'0'+c;
                ans[p3] = val%10 + '0';
                p1--; p2--;
                c = val/10;
            }   
            else if (p1>=0) {
                int val = num1[p1]-'0'+c;
                ans[p3] = val%10 + '0';
                p1--;
                c = val/10;
            }
            else {
                int val = num2[p2]-'0'+c;
                ans[p3] = val%10+'0';
                p2--;
                c = val/10;
            }
            p3--;
        }
        
        if (c)
            ans = "1" + ans;
        return ans;
    }
};
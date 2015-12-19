class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.length() < 0) return ans;
        unordered_map<int,int> tab;
        int v = 0, mask=(1<<18)-1;
        for (int i=0; i<10; i++) {
            v <<= 2;
            v += c2int(s[i]);
        }
        tab[v]++;
        for (int i=10; i<s.length(); i++) {
            v &= mask;
            v <<= 2;
            v += c2int(s[i]);
            tab[v]++;
            if (tab[v] == 2)
                ans.push_back(s.substr(i-9, 10));
        }
        return ans;
    }
    
    int c2int(char ch) {
        switch(ch) {
            case 'A': return 0;
            case 'T': return 1;
            case 'C': return 2;
            case 'G': return 3;
        }
    }
};
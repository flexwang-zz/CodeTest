class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string key[] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", "+", " ", "#" };
        int sum = 1;
        vector<string> strs;
        if (digits.size() == 0)
            return strs;
        for (int i = 0; i<digits.size(); i++) {
            if (digits[i] == '1') continue;
            sum *= key[digits[i] - '0'].size();
        }
        for (int i = 0; i<sum; i++) {
            int d = i;
            string s;
            for (int j = 0; j<digits.size(); j++) {
                char c = digits[j];
                if (c == '1') continue;
                s += key[c - '0'][d%key[c - '0'].size()];
                d /= key[c - '0'].size();
            }
            strs.push_back(s);
        }
        return strs;
    }

};
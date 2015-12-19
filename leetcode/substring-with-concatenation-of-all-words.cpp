class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> dict;
        for (string&word:words)
            dict[word]++;
        int wl = words[0].size();
        vector<int> ans;
        for (int i=0; i<wl; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> tdict;
            for (int j=i; j+wl<=s.length(); j+=wl) {
                string str = s.substr(j, wl);
                if (dict.find(str) == dict.end()) {
                    tdict.clear();
                    count = 0;
                    left = j+wl;
                }
                else {
                    tdict[str]++;
                    if (tdict[str] <= dict[str])
                        count ++;
                    else {
                        while (tdict[str] > dict[str]) {
                            string s2 = s.substr(left, wl);
                            tdict[s2]--;
                            if (tdict[s2] < dict[str]) count--;
                            left += wl;
                        }
                    }
                    if (count == words.size()) {
                        ans.push_back(left);
                        tdict[s.substr(left, wl)]--;
                        left += wl;
                        count--;
                    }
                }
            }
        }
        return ans;
    }
};
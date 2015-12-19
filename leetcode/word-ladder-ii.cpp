class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> head={start}, tail={end};
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> next;
        bool head_start = true;
        while (!head.empty() && !tail.empty()) {
            for (auto word:head) dict.erase(word);
            for (auto word:tail) dict.erase(word);
            if (head.size() > tail.size()) {
                swap(head, tail);
                head_start = !head_start;
            }
            unordered_set<string> temp_head;
            bool stop = false;
            for (auto word:head) {
                string original_word = word;
                for (int i=0; i<word.length(); i++) {
                    char temp = word[i];
                    for (char ch='a'; ch<='z'; ch++) {
                        if (ch == temp) continue;
                        word[i] = ch;
                        if (tail.find(word) != tail.end()) {
                            stop = true;
                            if (head_start) 
                                next[original_word].push_back(word);
                            else
                                next[word].push_back(original_word);
                        }
                        if (!stop && dict.find(word) != dict.end()) {
                            temp_head.insert(word);
                            if (head_start) 
                                next[original_word].push_back(word);
                            else
                                next[word].push_back(original_word);
                        }
                    }
                    word = original_word;
                }
            }
            if (stop) break;
            head = temp_head;
        }
        vector<string> v={start};
        dfs(ans, v, next, start, end);
        return ans;
    }
    
    void dfs(vector<vector<string>> &ans, vector<string> &v, unordered_map<string, vector<string>> &next, string s, string t) {
        if (s == t) {
            ans.push_back(v);
        }
        for (auto word:next[s]) {
            v.push_back(word);
            dfs(ans, v, next, word, t);
            v.pop_back();
        }
    }
};
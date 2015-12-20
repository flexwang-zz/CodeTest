class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0;
        vector<string> ans;
        while (i < words.size()) {
            int j = i + 1;
            int len = words[i].length();
            while (j < words.size() && len + words[j].length() + 1 <= maxWidth)
                len += words[j++].length() + 1;
            bool lastLine = false;
            if (j == words.size()) lastLine = true;
            int ngap = j - i - 1;
            int nspace = maxWidth - len;
            int space_per_gap = ngap == 0 ? 0:nspace / ngap;
            string line = words[i];
            for (int k = i + 1; k < j; k++) {
                if (!lastLine)
                    for (int l = 0; l<=space_per_gap; l++)
                        line += " ";
                if (k - i - 1 < nspace%ngap || lastLine)
                    line += " ";
                line += words[k];
            }
            line.resize(maxWidth, ' ');
            i = j;
            ans.push_back(line);
        }
        return ans;
    }
};
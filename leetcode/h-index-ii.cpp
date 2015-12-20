class Solution {
public:
    int hIndex(vector<int>& citations) {
        int npaper = citations.size();
        int l = 0, r = npaper+1;
        while (l+1 < r) {
            int m = (l+r) / 2;
            if (citations[npaper-m] >= m)
                l = m;
            else
                r = m;
        }
        return l;
    }
};
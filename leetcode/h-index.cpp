class Solution {
public:
    int hIndex(vector<int>& citations) {
        int nbucket = citations.size()+1;
        vector<int> buckets(nbucket, 0);
        for (auto c:citations) {
            int idx = c>=nbucket?0:nbucket-1-c;
            buckets[idx]++;
        }
        int h = 0;
        for (int i=0; i<nbucket; i++) {
            int cite = nbucket-1-i;
            h += buckets[i];
            if (cite <= h) return cite;
        }
        return nbucket-1;
    }
};
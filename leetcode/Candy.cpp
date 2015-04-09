class Solution {
public:
    int candy(vector<int> &ratings) {
        int len = ratings.size();
        int ans = len;
        vector<int> c(len, 0);
        vector<pair<int,int>> ps(len);
		for (int i=0; i<len; i++) {
			ps[i].first = ratings[i];
			ps[i].second = i;
		}
		sort(ps.begin(), ps.end());
        for (int i=0; i<len; i++) {
            int r = ps[i].first;
            int pos = ps[i].second;
            int cc = 0;
            if (pos > 0 && r > ratings[pos-1])
                cc = max(cc, c[pos-1]+1);
            if (pos < len-1 && r > ratings[pos+1])
                cc = max(cc, c[pos+1]+1);
            c[pos] = cc;
            ans += cc;
        }
        return ans;
    }
};
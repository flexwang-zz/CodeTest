class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;

        vector<pair<int, vector<int>>> v;
        v.push_back(make_pair(target, vector<int>()));

        for (int i = 0; i<candidates.size(); i++) {
            int len = v.size();
            for (int j = 0; j<len; j++) {
                if (v[j].first == 0) continue;
                for (int k = 1; k*candidates[i] <= v[j].first; k++) {
                    v.push_back(make_pair(v[j].first - k*candidates[i], v[j].second));
                    vector<int>& vp = v.back().second;
                    vp.resize(vp.size() + k, candidates[i]);
                }
            }
        }
        for (int i = 0; i<v.size(); i++) {
            if (v[i].first == 0) ans.push_back(v[i].second);
        }
        return ans;
    }
};
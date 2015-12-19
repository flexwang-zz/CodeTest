class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combinationSum2(ans, candidates, v, target, 0);
        
        return ans;
    }
    
    void combinationSum2(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& v, int target, int begin) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        
        for (int i=begin; i<candidates.size() && target >= candidates[i]; i++) {
            if (i != begin && candidates[i] == candidates[i-1]) continue;
            v.push_back(candidates[i]);
            combinationSum2(ans, candidates, v, target-candidates[i], i+1);
            v.pop_back();
        }
    }
};
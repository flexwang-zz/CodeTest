class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        permute(ans, nums, 0);
        return ans;
    }
    
    void permute(vector<vector<int>>& ans, vector<int>& perm, int begin)
    {
        if (begin == perm.size()) {
            ans.push_back(perm);
            return;
        }
        unordered_set<int> used;
        for (int i=begin; i<perm.size(); i++) {
            if (used.find(perm[i]) != used.end()) continue;
            used.insert(perm[i]);
            swap(perm[i], perm[begin]);
            permute(ans, perm, begin+1);
            swap(perm[i], perm[begin]);
        }
    }
};
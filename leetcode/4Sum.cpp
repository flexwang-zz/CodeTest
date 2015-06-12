class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size()-3; i++) {
            if (i && nums[i]==nums[i-1]) continue;
            for (int j=i+1; j<nums.size()-2; j++) {
                if (j!=i+1 && nums[j]==nums[j-1]) continue;
                int p1 = j+1;
                int p2 = nums.size()-1;
                int t = nums[i]+nums[j];
                while (p1 < p2) {
                    if (p1 != j+1 && nums[p1]==nums[p1-1]) {
                        p1++;
                        continue;
                    }
                    if (p2 != nums.size()-1 && nums[p2]==nums[p2+1]) {
                        p2--;
                        continue;
                    }
                    if (nums[p1]+nums[p2]+t == target) {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[p1]);
                        v.push_back(nums[p2]);
                        ans.push_back(v);
                        p1++;
                    }
                    else if (nums[p1]+nums[p2]+t < target)
                        p1++;
                    else
                        p2--;
                }
            }
            
        }
        
        return ans;
    }
};
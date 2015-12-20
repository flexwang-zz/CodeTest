class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i + 2 < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1])  continue;
            int p1 = i + 1;
            int p2 = nums.size() - 1;

            while (p1 < p2) {
                if (p1 > i + 1 && nums[p1] == nums[p1 - 1]) {
                    p1++;
                    continue;
                }
                if (p2 < nums.size() - 1 && nums[p2] == nums[p2 + 1]) {
                    p2--;
                    continue;
                }
                if (nums[p1] + nums[p2] < -nums[i])
                    p1++;
                else if (nums[p1] + nums[p2] > -nums[i])
                    p2--;
                else {
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[p1]);
                    t.push_back(nums[p2]);
                    ans.push_back(t);
                    p1++;
                }
            }
        }

        return ans;
    }
};
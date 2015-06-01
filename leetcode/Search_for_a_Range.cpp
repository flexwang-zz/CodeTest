class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        vector<int> ans(2, -1);
        while (l+1 < r) {
            int m = (l+r)>>1;
            if (nums[m] <= target)
                l = m;
            else
                r = m;
        }
        if (nums[l] != target)
            return ans;
        ans[1] = l;
        l = -1, r = nums.size()-1;
        while (l+1 < r) {
            int m = (l+r)>>1;
            if (nums[m] < target)
                l = m;
            else
                r = m;
        }
        ans[0] = r;
        return ans;
    }
};
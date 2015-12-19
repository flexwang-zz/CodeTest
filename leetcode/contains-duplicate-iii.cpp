class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> windows;
        int k2 = 0;
        for (int i=0; i<nums.size(); i++) {
            multiset<int>::iterator iter = windows.lower_bound(nums[i]-t);
            if (iter != windows.end() && *iter-nums[i] <= t)
                return true;
            windows.insert(nums[i]);
            if (k2 == k)
                windows.erase(windows.find(nums[i-k]));
            else
                k2++;
        }
        return false;
    }
    
};
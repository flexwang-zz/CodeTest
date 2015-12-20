class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = -1, r = nums.size()-1;
        while (l+1 < r) {
            int  m = (l+r)/2;
            if (nums[m] < nums[r])
                r = m;
            else
                l = m;
        }
        return nums[r];
    }
};
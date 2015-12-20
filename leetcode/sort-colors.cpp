class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, j=0, k=nums.size()-1;
        while (j<=k) {
            if (nums[j]<1) swap(nums[j++], nums[i++]);
            else if (nums[j] > 1) swap(nums[j], nums[k--]);
            else j++;
        }
    }
};
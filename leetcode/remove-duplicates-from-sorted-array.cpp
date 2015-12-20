class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nunique = 0;
        int pre;
        for (int i=0; i<nums.size(); i++) {
            if (i==0 || nums[i]!=pre) {
                pre = nums[i];
                nums[nunique++] = nums[i];
            }
        }
        return nunique;
    }
};
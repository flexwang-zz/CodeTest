class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) 
            while (nums[i] != i && nums[i] < nums.size())
                swap(nums[i], nums[nums[i]]);
        for (int i=0; i<nums.size(); i++)
            if (i != nums[i]) return i;
        return nums.size();
    }
};
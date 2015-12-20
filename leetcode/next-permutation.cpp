class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int p;
        for (p=nums.size()-1; p>0; p--) 
            if (nums[p] > nums[p-1])
                break;
        if (p) {
            int p2;
            for (p2=nums.size()-1; p2>p; p2--)
                if (nums[p2] > nums[p-1]) break;
            swap(nums[p2], nums[p-1]);
        }
        reverse(nums.begin()+p, nums.end());
    }
};
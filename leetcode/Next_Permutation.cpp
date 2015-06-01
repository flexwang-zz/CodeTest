class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int p;
        for (p=nums.size()-1; p>0; p--) 
            if (nums[p] > nums[p-1])
                break;
        if (p == 0) 
            sort(nums.begin(), nums.end());
        else {
            int p2 = p;
            for (int i=p+1; i<nums.size(); i++)
                if (nums[i] > nums[p-1] && nums[i] < nums[p2])
                    p2 = i;
            swap(nums[p-1], nums[p2]);
            sort(nums.begin()+p, nums.end());
        }
    }
};
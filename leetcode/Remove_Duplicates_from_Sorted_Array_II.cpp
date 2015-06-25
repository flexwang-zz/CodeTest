class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=0;
        int last=0, time=0;
        
        while (i < nums.size()) {
            if (nums[i] == last) 
                time++;
            else {
                time = 1;
                last = nums[i];
            }
            
            if (time <= 2) 
                nums[j++] = nums[i++];
            else
                i++;
        }
        return j;
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0x5fffffff;
        sort(nums.begin(), nums.end());

        for (int i = 0; i + 2 < nums.size(); i++) {
            int p1 = i + 1;
            int p2 = nums.size() - 1;

            while (p1 < p2) {
                if (abs(nums[i] + nums[p1] + nums[p2] - target) < abs(ans - target))
                    ans = nums[i] + nums[p1] + nums[p2];
                if (nums[i] + nums[p1] + nums[p2] < target)
                    p1++;
                else
                    p2--;
            }
        }
        return ans;
    }
};
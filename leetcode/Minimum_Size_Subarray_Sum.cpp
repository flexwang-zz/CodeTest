class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int a = 0, b = 0;
        int ans = INT_MAX;
        for (;;) {
            if (sum < s) {
                if (b >= nums.size())
                    break;
                sum += nums[b++];
            }
            else {
                ans = min(ans, b-a);
                sum -= nums[a++];
            }
        }
        if (ans == INT_MAX)
            return 0;
    }
};
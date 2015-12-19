class Solution {
public:
    void rotate2(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        reverse(nums, len-k, len-1);
        reverse(nums, 0, len-k-1);
        reverse(nums, 0, nums.size()-1);
    }
    
    int gcd(int a, int b) {
        return b?gcd(b, a%b):a;
    }
    
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (!len) return;
        k %= len;
        if (!k) return;
        int g = gcd(k, len);
        for (int i=0; i<g; i++) {
            int temp = nums[i];
            for (int j=0; i+j*g<len; j++)
                swap(temp, nums[(i+j*k+k)%len]);
        }
    }
    
    void reverse(vector<int>& nums, int s, int t) {
        while (s < t) {
            swap(nums[s], nums[t]);
            s++;
            t--;
        }
    }
};
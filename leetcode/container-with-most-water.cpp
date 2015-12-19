class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;

        int s = 0, t = height.size()-1;
        
        while (s < t) {
            ans = max(ans, min(height[s], height[t])*(t-s));
            if (height[s] < height[t])
                s++;
            else
                t--;
        }
        return ans;
    }
};
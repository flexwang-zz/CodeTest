class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        
        for (int i=0; i<nums.size(); i++)
            if (que.size() < k)
                que.push(nums[i]);
            else if (que.top() < nums[i]) {
                que.pop();
                que.push(nums[i]);
            }
        return que.top();
            
    }
};
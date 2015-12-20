/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
    
    int maxPathSum(TreeNode* node, int &ans) {
        //1
        if (!node) 
            return 0;
        
        //2
        int left_chain = max(0, maxPathSum(node->left, ans));
        int right_chain = max(0, maxPathSum(node->right, ans));
        
        ans = max(ans, left_chain + node->val + right_chain);
        return max(left_chain+node->val, right_chain+node->val);
    }
};
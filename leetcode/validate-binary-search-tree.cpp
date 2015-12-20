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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
    
    bool isValidBST(TreeNode* root, const int *low, const int *up) {
        if (!root) return true;
        int val = root->val;
        if ((low && val <= *low) || (up && val >= *up)) return false;
        return isValidBST(root->left, low, &val)
            && isValidBST(root->right, &val, up);
    }
};
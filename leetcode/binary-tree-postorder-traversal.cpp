/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        
        vector<TreeNode*> stack;
        
        stack.push_back(root);
        
        while(stack.size())
        {
            TreeNode* t = stack.back();
            stack.pop_back();
            
            if( t)
            {
                result.insert(result.begin(), t->val);
                
                stack.push_back(t->left);
                stack.push_back(t->right);
            }
        }
        
        return result;
        
    }
};
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        
        vector<TreeNode*> stack;
        
        TreeNode* curnode = root;
        
        do
        {
            while(curnode)
            {
                stack.push_back(curnode);
                curnode = curnode->left;
            }
            
            if( stack.size())
            {
                curnode = stack.back();
                stack.pop_back();
                
                result.push_back(curnode->val);
                
                curnode = curnode->right;
            }
            
            
        }while(stack.size() || curnode);
        
        return result;
    }
};
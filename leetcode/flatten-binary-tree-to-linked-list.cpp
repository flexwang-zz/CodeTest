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
    void flatten(TreeNode *root) {
        
        TreeNode *last = root;
        
        flatten(root, last);
    }
    
    void flatten(TreeNode *root, TreeNode *&last)
    {
        if (!root)
        {            
            return;
        }
        
		last = root;
		
        TreeNode* right = root->right;
        
        flatten(root->left, last);  //flatten the root->left
        
        root->right = root->left;   //linked the flattened root->left to the root->right
        
        last->right = right;    //linked the origin root->right to the most right of the current root->right
        
        root->left = NULL;      //empty root->left
        
        flatten(right, last);   //flatten the root->right
    }
};
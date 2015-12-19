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
    bool isSymmetric(TreeNode *root) {
        if (root)
        {
            return isSymmetric(root->right, root->left);
        }
        
        return true;
    }
    
    bool isSymmetric(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 && !r2)
        {
            return true;   
        }
        else if (r1 && r2)
        {
            if (r1->val != r2->val)
            {
                return false;
            }
            
            return isSymmetric(r1->right, r2->left) && isSymmetric(r1->left, r2->right);
        }
        else
        {
            return false;
        }
    }
};
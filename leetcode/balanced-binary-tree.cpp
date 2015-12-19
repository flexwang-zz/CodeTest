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
    bool isBalanced(TreeNode *root) {
        return height(root)>=0;
    }
    
    int max( int a, int b)
    {
        return (a>b)?a:b;    
    }
    
    int abs(int a)
    {
        return a>=0?a:-a;
    }
    
    int height(TreeNode* node)
    {
        if( node)
        {
            int left = height(node->left);
            int right = height(node->right);
            
            
            if( left < 0 || right < 0)
            {
                return -1;
            }
            
            if( abs(left-right) >= 2)
            {
                return -1;
            }
            
           return max(height(node->right), height(node->left)) + 1;
        }
        else
        {
            return 0;
        }
    }
};
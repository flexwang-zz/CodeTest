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
    int maxPathSum(TreeNode *root) {
        int max = root->val;
        
        maxPathSum(root, max);
        
        return max;
    }
    
    int max2(int a, int b)
    {
        return a>b?a:b;
    }
    
    int max3(int a, int b, int c)
    {
        return max2(a,(max2(b,c)));
    }
    
    int maxPathSum(TreeNode *root, int &max)
    {
        if (!root)
        {
            return 0;
        }
        
        int left = maxPathSum(root->left, max);
        int right = maxPathSum(root->right, max);
        
        int m = max3(root->val+left, root->val+right, root->val+left+right);
        
        if (m > max)
        {
            max = m;
        }
        
        return max3(root->val, root->val+left, root->val+right);
    }
};
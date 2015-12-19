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
    int maxDepth(TreeNode *root) {
        int depth = 0;
        vector<TreeNode*> curlayer;
        
        if( root)
        {
            curlayer.push_back(root);
        }
        
        while( curlayer.size())
        {
            depth++;
            vector<TreeNode*> nextlayer;
            for( int i=0,size=curlayer.size(); i<size; i++)
            {
                if( curlayer[i]->left)
                {
                    nextlayer.push_back(curlayer[i]->left);
                }
                if( curlayer[i]->right)
                {
                    nextlayer.push_back(curlayer[i]->right);
                }
            }
            curlayer = nextlayer;
        }
        
        return depth;
    }
};
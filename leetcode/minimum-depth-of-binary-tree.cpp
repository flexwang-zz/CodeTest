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
    int minDepth(TreeNode *root) {
        int depth = 0;
        
        if( !root)
        {
            return depth;
        }
        
        vector<TreeNode*> curlayer;
        curlayer.push_back(root);
        while(true)
        {
            vector<TreeNode*> nextlayer;
            
            for( int i=0,size=curlayer.size(); i<size; i++)
            {
                if( !curlayer[i]->left && !curlayer[i]->right)
                {
                    return depth+1;
                }
                else
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
            }
            
            curlayer = nextlayer;
            
            depth ++;
        }
    }
};
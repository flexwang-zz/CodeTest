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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<TreeNode*> curlayer;
        vector<vector<int>> result;
        
        if( !root)
        {
            return result;
        }
        
        curlayer.push_back(root);
        
        while(curlayer.size())
        {
            vector<TreeNode*> nextlayer;
            vector<int> r;
            for(int i=0,size=curlayer.size(); i<size; i++)
            {

                r.push_back(curlayer[i]->val);
                
                if( curlayer[i]->left)
                {
                    nextlayer.push_back(curlayer[i]->left);
                }
                    
                if( curlayer[i]->right)
                {
                    nextlayer.push_back(curlayer[i]->right);
                }
            }
            result.insert(result.begin(), r);
            curlayer = nextlayer;
        }
        
        return result;
    }
};
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        
        vector<vector<int>> result;
        
        vector<TreeNode*> curlayer;
        
        if (root)
        {
            curlayer.push_back(root);
        }
        
        while (curlayer.size())
        {
            vector<int> layer;
            vector<TreeNode*> nextlayer;
            
            for (int i=0, size=curlayer.size(); i<size; i++)
            {
                layer.push_back(curlayer[i]->val);
                
                if (curlayer[i]->left)
                {
                    nextlayer.push_back(curlayer[i]->left);
                }
                
                if (curlayer[i]->right)
                {
                    nextlayer.push_back(curlayer[i]->right);
                }
            }
            
            if (layer.size())
            {
                result.push_back(layer);
            }
            
            curlayer = nextlayer;
        }
        
        return result;
    }
};
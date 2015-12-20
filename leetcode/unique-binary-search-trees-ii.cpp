/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        
        if (n == 0) return vector<TreeNode*>(1, NULL);
        vector<vector<vector<TreeNode*>>> dp(n+2, vector<vector<TreeNode*>>(n+2));
        for (int i=1; i<=n+1; i++) {
            dp[i][i].push_back(new TreeNode(i));
            dp[i][i-1].push_back(NULL);
        }
        
        for (int l=2; l<=n; l++) {
            for (int i=1; i<=n && i+l-1<=n; i++) {
                for (int j=i; j<=i+l-1; j++) {
                    for (int m=0; m<dp[i][j-1].size(); m++)
                    for (int n=0; n<dp[j+1][i+l-1].size(); n++) {
                        TreeNode* node = new TreeNode(j);
                        node->left = dp[i][j-1][m];
                        node->right = dp[j+1][i+l-1][n];
                        dp[i][i+l-1].push_back(node);
                    }
                }
            }
        }
        return dp[1][n];
        
        //return generateTrees(1, n);
    }
    
    vector<TreeNode*> generateTrees(int s, int t) {
        vector<TreeNode*> ans;
        if (s > t) {
            ans.push_back(NULL);
            return ans;
        }
        for (int i=s; i<=t; i++) {
            vector<TreeNode*> lefts = generateTrees(s, i-1);
            vector<TreeNode*> rights = generateTrees(i+1, t);
            
            for (int j=0; j<lefts.size(); j++) {
                for (int k=0; k<rights.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lefts[j];
                    root->right = rights[k];
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
};
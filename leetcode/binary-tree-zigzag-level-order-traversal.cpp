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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        int level_cnt = 0;
        deque<TreeNode*> q;
        
        if (root) q.push_back(root);
        int pop_cnt = 1, push_cnt = 0;
        
        vector<int> temp;
        while (!q.empty()) {
            TreeNode *node;
            if (level_cnt%2 == 1) {
                node = q.back();
                q.pop_back();
            }
            else {
                node = q.front();
                q.pop_front();
            }
            pop_cnt--;
            temp.push_back(node->val);
            if (level_cnt%2 == 0) {
                if (node->left) {
                    q.push_back(node->left);
                    push_cnt++;
                }
                if (node->right) {
                    q.push_back(node->right);
                    push_cnt++;
                }
            }
            else {
                if (node->right) {
                    q.push_front(node->right);
                    push_cnt++;
                }
                if (node->left) {
                    q.push_front(node->left);
                    push_cnt++;
                }
            }
            
            if (pop_cnt == 0) {
                pop_cnt = push_cnt;
                push_cnt = 0;
                level_cnt ++;
                ans.push_back(temp);
                temp.clear();
            }
        }
        
        return ans;
    }
};
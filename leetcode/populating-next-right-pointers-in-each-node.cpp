/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode* getNode(TreeLinkNode* root, int id, int level) {
        int mask = (1<<level) - 1;
        id &= mask;
        if (!id) return NULL;
        TreeLinkNode * node = root;
        for (int i=level-1; i>=0; i--)
            if (id & (1<<i)) node = node->right;
            else node = node->left;
        return node;
    }
    
    void connect(TreeLinkNode *node, int id, int level, TreeLinkNode *root) {
        if (!node) return;
        node->next = getNode(root, id+1, level);
        connect(node->left, id<<1, level+1, root);
        connect(node->right, (id<<1)+1, level+1, root);
    }
    
    void connect(TreeLinkNode *root) {
        connect(root, 0, 0, root);    
    }
};
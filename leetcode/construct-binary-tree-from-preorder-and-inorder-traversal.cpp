class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        int s = 0;
        buildTree(preorder, s, inorder, 0, inorder.size(), root);
        return root;
    }

    void buildTree(vector<int>& preorder, int& s, vector<int>& inorder, int left, int right, TreeNode* &node)
    {
        if (left == right) {
            node = NULL;
            return;
        }
        int i;
        for (i = left; i < right; i++) {
            if (inorder[i] == preorder[s])
                break;
        }
        node = new TreeNode(preorder[s]);
        if (i != left)
            buildTree(preorder, ++s, inorder, left, i, node->left);
        if (i != right - 1)
            buildTree(preorder, ++s, inorder, i+1, right, node->right);
    }
};
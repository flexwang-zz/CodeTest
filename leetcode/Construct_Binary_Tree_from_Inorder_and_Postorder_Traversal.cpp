class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root;
        int s = postorder.size()-1;
        buildTree(postorder, s, inorder, 0, inorder.size(), root);
        return root;
    }

    void buildTree(vector<int>& postorder, int& s, vector<int>& inorder, int left, int right, TreeNode* &node)
    {
        if (left == right) {
            node = NULL;
            return;
        }

        int i;
        for (i = left; i < right; i++) {
            if (inorder[i] == postorder[s])
                break;
        }
        node = new TreeNode(postorder[s]);

        if (i != right - 1)
            buildTree(postorder, --s, inorder, i + 1, right, node->right);
        if (i != left)
            buildTree(postorder, --s, inorder, left, i, node->left);
    }
};
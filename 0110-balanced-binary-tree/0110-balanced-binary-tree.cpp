class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int x = maxDepth(root->left);
        int y = maxDepth(root->right);

        if (abs(x - y) > 1)
            return false;

        // check recursively if left and right subtrees are balanced
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

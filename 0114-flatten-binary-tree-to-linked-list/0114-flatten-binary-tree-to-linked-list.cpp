/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = nullptr;

    void preorder(TreeNode* root) {
        if (!root) return;

        if (prev) {
            prev->right = root;
            prev->left = nullptr;
        }

        prev = root;

        // Save original left and right because they might be changed
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        preorder(left);
        preorder(right);
    }

    void flatten(TreeNode* root) {
        prev = nullptr;
        preorder(root);
    }
};

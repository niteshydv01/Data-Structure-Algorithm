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
    int rob(TreeNode* root) {
        if (!root)
            return 0;
        if (root->val < 0)
            return root->val * -1;

        int including_root = 0, not_including_root = 0;
        including_root += root->val;
        if (root->left) {
            including_root += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            including_root += rob(root->right->left) + rob(root->right->right);
        }
        not_including_root += rob(root->left) + rob(root->right);
        int res = max(including_root, not_including_root);
        root->val = res * -1;
        return res;
    }

};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if (root == NULL)
            return true;

        bool lh = checkTree(root->left);
        bool rh = checkTree(root->right);

        // ✅ Fix 1: use == instead of = for comparison
        // ✅ Fix 2: check if both children exist before accessing their values
        if (root->left && root->right &&
            root->val == root->left->val + root->right->val)
            return  lh && rh;

       
           
        if (!root->left && !root->right)
            return true;

        return false;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*class Solution {
public:
    bool symmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL) {
            return left == right;
        }
        if (left->val != right->val) {
            return false;
        }
        return symmetric(left->left, right->right) && symmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return symmetric(root->left, root->right);
    }
};*/
class Solution {
public:
    bool symmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
           return true;
        }
        if (left == NULL || right == NULL) {
           return false;
        }
        if (left->val == right->val) {
            return symmetric(left->left, right->right) && symmetric(left->right, right->left);
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return symmetric(root->left, root->right);
    }
};

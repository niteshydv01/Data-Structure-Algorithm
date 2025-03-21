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
    int count = 0;  // Counter to track elements
    int result;      // Store the k-th smallest value

    void inorder(TreeNode* root, int k) {
        if (!root) return;

        inorder(root->left, k);  // Visit left subtree

        count++;
        if (count == k) {  // When k-th smallest is found
            result = root->val;
            return;
        }

        inorder(root->right, k); // Visit right subtree
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};

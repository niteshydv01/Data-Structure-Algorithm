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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr; // Base case: empty tree
        
        // Search for the node with the given key
        if (root->val > key) {
            root->left = deleteNode(root->left, key); // Recursively delete in left subtree
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key); // Recursively delete in right subtree
        } else { // Found the node with the key
            if (!root->left) { // Case 1: No left child
                TreeNode* temp = root->right;
                delete root;
                return temp; // Update root pointer
            } else if (!root->right) { // Case 2: No right child
                TreeNode* temp = root->left;
                delete root;
                return temp; // Update root pointer
            } else { // Case 3: Node has both left and right children
                // Find the inorder successor (minimum value in the right subtree)
                TreeNode* temp = findMin(root->right);
                // Copy the inorder successor's content to this node
                root->val = temp->val;
                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root; // Return the updated root pointer
    }
    
    TreeNode* findMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};
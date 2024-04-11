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
        TreeNode* curr = root;
        TreeNode* parent = nullptr;
        
        // Search for the node with the given key
        while (curr != nullptr && curr->val != key) {
            parent = curr;
            if (key < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        
        // If the key is not found, return the original root
        if (curr == nullptr) return root;
        
        // Case 1: Node to delete has no children or one child
        if (curr->left == nullptr) {
            if (parent == nullptr) {
                root = curr->right;
            } else if (parent->left == curr) {
                parent->left = curr->right;
            } else {
                parent->right = curr->right;
            }
            delete curr;
        } else if (curr->right == nullptr) {
            if (parent == nullptr) {
                root = curr->left;
            } else if (parent->left == curr) {
                parent->left = curr->left;
            } else {
                parent->right = curr->left;
            }
            delete curr;
        }
        // Case 2: Node to delete has two children
        else {
            TreeNode* successor = findSuccessor(curr->right);
            curr->val = successor->val;
            curr->right = deleteNode(curr->right, successor->val);
        }
        
        return root;
    }
    
    TreeNode* findSuccessor(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};

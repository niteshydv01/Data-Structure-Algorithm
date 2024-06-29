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
    void solve(TreeNode* root, unordered_map<TreeNode*, bool>& visited, int &count) {
        if (!root) {
            return;
        }
        if (!visited[root]) {
            count++;
        }
        visited[root] = true;
        solve(root->left, visited, count);
        solve(root->right, visited, count);
    }

    int countNodes(TreeNode* root) {
        unordered_map<TreeNode*, bool> visited;
        int count = 0;
        solve(root, visited, count);
        return count;
    }
};
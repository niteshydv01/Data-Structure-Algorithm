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
/*class Solution {
public:
    void dfs(TreeNode* node, int level, vector<int>& result) {
        if (!node) return;

        // If this is the first time we're visiting this level
        if (level == result.size()) {
            result.push_back(node->val);
        }

        // Right-first traversal
        dfs(node->right, level + 1, result);
        dfs(node->left, level + 1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
};
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();

                // If it's the last node in the current level, add to result
                if (i == levelSize - 1) {
                    ans.push_back(current->val);
                }

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }

        return ans;
    }
};


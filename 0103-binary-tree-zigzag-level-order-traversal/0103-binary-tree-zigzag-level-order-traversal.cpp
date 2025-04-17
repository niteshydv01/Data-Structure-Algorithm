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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool ltr = true;

        while (!q.empty()) {
            int n = q.size();
            vector<int> a(n);

            for (int i = 0; i < n; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                // Place the value in the correct position based on the current direction
                int index = ltr ? i : n - 1 - i;
                a[index] = curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            ans.push_back(a);
            ltr = !ltr;  // Toggle the direction
        }

        return ans;
    }
};
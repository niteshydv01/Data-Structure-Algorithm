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
#define tn TreeNode

    // int cnt = 0;

    void helper(tn* root, int mx, int& cnt) {
        if (!root)
            return;
        mx = max(root->val, mx);
        if (root->val >= mx)
            cnt++;
        helper(root->left, mx, cnt);
        helper(root->right, mx, cnt);
    }

    int goodNodes(TreeNode* root) {
        int cnt = 0;
        helper(root, INT_MIN, cnt);
        return cnt;
    }
};


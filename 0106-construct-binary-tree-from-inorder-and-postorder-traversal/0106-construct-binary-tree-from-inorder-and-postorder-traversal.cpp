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
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inMap[rootVal];

        // Note: build right subtree first
        root->right = build(inorder, postorder, inIndex + 1, inEnd, inMap);
        root->left = build(inorder, postorder, inStart, inIndex - 1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        int n = inorder.size();

        for (int i = 0; i < n; ++i) {
            inMap[inorder[i]] = i;
        }

        postIndex = n - 1;  // Start from the last postorder element
        return build(inorder, postorder, 0, n - 1, inMap);
    }
};

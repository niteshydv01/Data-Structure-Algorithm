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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inMap[rootVal];  // Index of root in inorder

        root->left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1, inMap);
        root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd, inMap);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());  // inorder traversal of BST is sorted preorder

        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;  // map value to index for quick lookup
        }

        int preIndex = 0;
        return buildTree(preorder, inorder, preIndex, 0, inorder.size() - 1, inMap);
    }
};

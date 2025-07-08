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
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        if (inStart > inEnd) return nullptr;

        
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        
        if (inStart == inEnd) return root;

       
        int inIndex = inMap[rootVal];

        
        root->left = build(preorder, inorder, inStart, inIndex - 1, inMap);
        root->right = build(preorder, inorder, inIndex + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;

        
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, inorder.size() - 1, inMap);
    }
};

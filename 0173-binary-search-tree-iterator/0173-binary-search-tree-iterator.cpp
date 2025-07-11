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
class BSTIterator {
public:
    vector<TreeNode*> inorder;
    int index = 0;

    void inOrder(TreeNode* root, vector<TreeNode*>& inorder) {
        if (!root) return;
        inOrder(root->left, inorder);
        inorder.push_back(root);
        inOrder(root->right, inorder);
    }

    BSTIterator(TreeNode* root) {
        inOrder(root, inorder);
    }

    int next() {
        return inorder[index++]->val;
    }

    bool hasNext() {
        return index < inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
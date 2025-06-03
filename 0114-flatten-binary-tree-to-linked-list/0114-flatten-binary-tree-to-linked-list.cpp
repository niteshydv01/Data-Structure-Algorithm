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
    stack<TreeNode*> s;  
    void DFS(TreeNode *root){
        if(root==nullptr){
            return ;
        }
        s.push(root);
        DFS(root->left);
        DFS(root->right);
    }
    void flatten(TreeNode* root) {
         DFS(root);
         while(!s.empty()){
            TreeNode *tem=s.top();
            s.pop();
            if(s.empty()){
                tem->left=nullptr;
            }
            else{
                s.top()->right=tem;
                tem->left=nullptr;
            }
         }
    }
};
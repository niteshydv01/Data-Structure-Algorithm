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
    void sol(vector<int>& sums, vector<vector<int>>& ans, int tt, TreeNode* temp, int targetSum) {
        if (temp == nullptr) return;
        tt += temp->val;
        sums.push_back(temp->val);
        if (tt == targetSum && temp->left == nullptr && temp->right == nullptr) {
            ans.push_back(sums);
        }
        sol(sums, ans, tt, temp->left, targetSum);
        sol(sums, ans, tt, temp->right, targetSum);
        sums.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> sums;
        vector<vector<int>> ans;
        sol(sums, ans, 0, root, targetSum);
        return ans;
    }
};
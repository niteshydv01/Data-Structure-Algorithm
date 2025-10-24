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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> result;
        serialize(root, mp, result);
        return result;
    }

    string serialize(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& result) {
        if (!root) return "#"; // null representation
        
        string key = to_string(root->val) + "," + 
                     serialize(root->left, mp, result) + "," +
                     serialize(root->right, mp, result);
        
        // If this serialization has been seen once before, record this subtree
        if (mp[key] == 1) {
            result.push_back(root);
        }
        mp[key]++;
        
        return key;
    }
};


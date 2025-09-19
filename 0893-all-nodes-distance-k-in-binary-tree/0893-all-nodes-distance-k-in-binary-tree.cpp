/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack, TreeNode* target) {
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            
            if (current->left) {
                parentTrack[current->left] = current;
                queue.push(current->left);
            }
            
            if (current->right) {
                parentTrack[current->right] = current;
                queue.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        markParents(root, parentTrack, target);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        
        int currLevel = 0;
        
        while (!queue.empty()) {
            int size = queue.size();
            if (currLevel == K) break;
            currLevel++;
            for (int i = 0; i < size; i++) {
                TreeNode* current = queue.front();
                queue.pop();
                
                if (current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                
                if (current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                
                if (parentTrack[current] && !visited[parentTrack[current]]) {
                    queue.push(parentTrack[current]);
                    visited[parentTrack[current]] = true;
                }
            }
        }
        
        vector<int> result;
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            result.push_back(current->val);
        }
        
        return result;
    }
};
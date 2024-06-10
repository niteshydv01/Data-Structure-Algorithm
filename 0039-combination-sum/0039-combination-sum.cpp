#include <vector>
using namespace std;

class Solution {
public:
    void solve(int n, vector<int>& candidates, int target, int i, int sum, vector<vector<int>>& ans, vector<int>& temp) {
        if (i >= n) {
            return;
        }
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        // Skip the current element
        solve(n, candidates, target, i + 1, sum, ans, temp);
        // Include the current element and proceed
        if (sum + candidates[i] <= target) {
            temp.push_back(candidates[i]);
            solve(n, candidates, target, i, sum + candidates[i], ans, temp); // Notice the i (not i + 1) for reusing the same element
            temp.pop_back(); // Backtrack
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(n, candidates, target, 0, 0, ans, temp);
        return ans;
    }
};

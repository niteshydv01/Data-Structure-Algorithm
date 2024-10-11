class Solution {
public:
    // Helper function to find combinations
    void solve(int n, vector<int>& candidates, int target, int i, int sum, vector<vector<int>>& ans, vector<int>& temp) {
        if (sum == target) {
            ans.push_back(temp);  // If target is reached, add the current combination
            return;
        }
        if (i >= n || sum > target) {
            return;  // If index exceeds size or sum exceeds target, stop
        }

        // Include the current element and proceed
        if (sum + candidates[i] <= target) {
            temp.push_back(candidates[i]);
            solve(n, candidates, target, i + 1, sum + candidates[i], ans, temp); 
            temp.pop_back();  // Backtrack
        }

        // Skip the current element and move to the next unique element
        while (i + 1 < n && candidates[i] == candidates[i + 1]) {
            i++;
        }
        solve(n, candidates, target, i + 1, sum, ans, temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates.size(), candidates, target, 0, 0, ans, temp);
        return ans;
    }
};

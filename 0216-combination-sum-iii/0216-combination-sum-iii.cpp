class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, int sum,
               vector<vector<int>>& ans, vector<int>& temp, int k) {
        if (temp.size() == k && sum == target) {
            ans.push_back(temp);
            return;
        }
        if (i >= candidates.size() || sum > target || temp.size() > k) return;

        // Include current element
        temp.push_back(candidates[i]);
        solve(candidates, target, i + 1, sum + candidates[i], ans, temp, k);
        temp.pop_back();

        // Skip current element
        solve(candidates, target, i + 1, sum, ans, temp, k);
    }

    vector<vector<int>> combinationSum3(int k, int n) { 
        vector<int> nums;
        for (int i = 1; i <= 9; i++) nums.push_back(i);

        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, n, 0, 0, ans, temp, k);
        return ans;
    }
};

class Solution {
public:
    void solve(int i, int n, int tar,
               vector<int>& curr,
               vector<vector<int>>& ans,
               vector<int>& candidates) {

        if (tar == 0) {
            ans.push_back(curr);
            return;
        }

        if (i >= n || tar < 0) {
            return;
        }

       
        curr.push_back(candidates[i]);
        solve(i, n, tar - candidates[i],
              curr, ans, candidates);
        curr.pop_back();

       
        solve(i + 1, n, tar,
              curr, ans, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, candidates.size(),
              target, curr, ans, candidates);

        return ans;
    }
};
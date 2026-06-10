class Solution {
public:
    int solve(vector<int>& nums, int n, int ind, int prevind,
              vector<vector<int>>& dp) {
        if (ind == n) {
            return 0;
        }
        if (dp[ind][prevind + 1] != -1) {
            return dp[ind][prevind + 1];
        }
        int take = 0;
        int skip;
        skip = solve(nums, n, ind + 1, prevind, dp);

        if (prevind == -1 || nums[ind] > nums[prevind]) {
            take = 1 + solve(nums, n, ind + 1, ind, dp);
        }

        return dp[ind][prevind+1] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(nums, n, 0, -1, dp);
    }
};
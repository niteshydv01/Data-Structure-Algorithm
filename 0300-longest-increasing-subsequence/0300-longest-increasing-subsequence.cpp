class Solution {
public:
    int solve(vector<int>& nums, int n, int index, int prevIndex,
              vector<vector<int>>& dp) {

        if (index == n)
            return 0;

        if (dp[index][prevIndex + 1] != -1)
            return dp[index][prevIndex + 1];

        int take = 0, skip = solve(nums, n, index + 1, prevIndex, dp);

        if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
            take = 1 + solve(nums, n, index + 1, index, dp);
        }

        return dp[index][prevIndex + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(nums, n, 0, -1, dp);
    }
};

class Solution {
public:
    int solve(vector<int>& nums, int n, int index, int prevIndex, vector<vector<int>>& dp) {
        // Base case: If we reach the end of the array
        if (index == n) return 0;

        // If already computed, return the stored result
        if (dp[index][prevIndex + 1] != -1) return dp[index][prevIndex + 1];

        // Option 1: Skip the current element
        int take = 0, skip = solve(nums, n, index + 1, prevIndex, dp);

        // Option 2: Take the current element (if it forms an increasing subsequence)
        if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
            take = 1 + solve(nums, n, index + 1, index, dp);
        }

        // Store the result in dp array
        return dp[index][prevIndex + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // Initialize dp array
        return solve(nums, n, 0, -1, dp);
    }
};

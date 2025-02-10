class Solution {
public:
    int countPartitionsUtil(int ind, int target, vector<int>& arr,
                            vector<vector<int>>& dp) {
        // Base cases
        if (ind == 0) {
            if (target == 0 && arr[0] == 0)
                return 2; // Two ways to partition: include or exclude the
                          // element
            if (target == 0 || target == arr[0])
                return 1; // One way to partition: include or exclude the
                          // element
            return 0;     // No way to partition
        }

        // If the result for this index and target sum is already calculated,
        // return it
        if (dp[ind][target] != -1)
            return dp[ind][target];

        // Calculate the number of ways without taking the current element
        int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);

        // Calculate the number of ways by taking the current element
        int taken = 0;
        if (arr[ind] <= target)
            taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);

        // Store the sum of ways in the DP array and return it
        return dp[ind][target] = (notTaken + taken);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            totSum += nums[i];
        }

        // Checking for edge cases
        if (totSum - target < 0)
            return 0; // Not possible to achieve the target sum
        if ((totSum - target) % 2 == 1)
            return 0; // The difference between the total sum and target sum
                      // must be even

        int s2 =
            (totSum - target) / 2; // Calculate the required sum for each subset

        vector<vector<int>> dp(n,
                               vector<int>(s2 + 1, -1)); // Initialize DP table
        return countPartitionsUtil(n - 1, s2, nums, dp);
    }
};
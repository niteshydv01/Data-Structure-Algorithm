class Solution {
public:
    int solve(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        // Base case: If we have only one type of coin left
        if (ind == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e9; // Large number to indicate impossibility
        }

        // Memoization check
        if (dp[ind][amount] != -1) return dp[ind][amount];

        // Not take the current coin
        int notTake = solve(ind - 1, coins, amount, dp);

        // Take the coin (if possible)
        int take = 1e9; // Large value if we can't take
        if (coins[ind] <= amount) {
            take = 1 + solve(ind, coins, amount - coins[ind], dp); // Stay at `ind` since coins can be reused
        }

        return dp[ind][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int result = solve(n - 1, coins, amount, dp);
        return (result >= 1e9) ? -1 : result; // If result is still large, return -1 (not possible)
    }
};

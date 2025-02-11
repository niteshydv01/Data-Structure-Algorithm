class Solution{
    public:
    int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    return solveMemo(coins, amount, 0, dp);
}

int solveMemo(vector<int>& coins, int amount, int index, vector<vector<int>>& dp) {
    if (amount == 0) {
        return 1;
    }
    if (amount < 0 || index >= coins.size()) {
        return 0;
    }
    if (dp[index][amount] != -1) {
        return dp[index][amount];
    }

    int take = solveMemo(coins, amount - coins[index], index, dp);
    int dontTake = solveMemo(coins, amount, index + 1, dp);

    dp[index][amount] = take + dontTake;

    return dp[index][amount];
}

};
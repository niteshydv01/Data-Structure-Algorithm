class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int n, vector<int>& cost, vector<int>& time) {
        if (n <= 0) return 0; // No walls left to paint
        if (i == cost.size()) return 1e9; // Ran out of painters

        if (dp[i][n] != -1) return dp[i][n];

        // Option 1: Skip this painter
        int skip = solve(i + 1, n, cost, time);

        // Option 2: Use this painter
        int take = cost[i] + solve(i + 1, max(0, n - time[i] - 1), cost, time);

        return dp[i][n] = min(skip, take);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(0, n, cost, time);
    }
};

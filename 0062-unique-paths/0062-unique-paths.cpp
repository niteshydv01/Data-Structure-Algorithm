class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp) {
        // Base case: If we reach the start of the grid
        if (i == 0 && j == 0) return 1;

        // Out of bounds check
        if (i < 0 || j < 0) return 0;

        // If already computed, return stored result
        if (dp[i][j] != -1) return dp[i][j];

        // Move from left and from top
        int left = solve(i, j - 1, dp);
        int up = solve(i - 1, j, dp);

        return dp[i][j] = left + up; // Store result
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize memoization table
        return solve(m - 1, n - 1, dp); // Start from bottom-right corner
    }
};
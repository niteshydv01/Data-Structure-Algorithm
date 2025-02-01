class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
        // Base case: If we reach the start of the grid
        if (i == 0 && j == 0) return (obstacleGrid[i][j] == 0) ? 1 : 0;

        // Out of bounds check
        if (i < 0 || j < 0 || obstacleGrid[i][j] == 1) return 0;

        // If already computed, return stored result
        if (dp[i][j] != -1) return dp[i][j];

        // Move from left and from top
        int left = solve(i, j - 1, dp, obstacleGrid);
        int up = solve(i - 1, j, dp, obstacleGrid);

        return dp[i][j] = left + up; // Store result
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If the start or end cell has an obstacle, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize memoization table
        return solve(m - 1, n - 1, dp, obstacleGrid);
    }
};

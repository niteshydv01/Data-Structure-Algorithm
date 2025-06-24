class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int n, int m, int i, int j) {
        if (i >= n || j >= m)
            return 1e9;  // Out of bounds → return large number

        if (i == n - 1 && j == m - 1)
            return grid[i][j];  

        if (dp[i][j] != -1)
            return dp[i][j]; 

        int rightAns = solve(grid, dp, n, m, i, j + 1);  // Move right
        int downAns = solve(grid, dp, n, m, i + 1, j);   // Move down

        int sans = min(rightAns, downAns);  
        int ans = grid[i][j] + sans;        

        return dp[i][j] = ans;             
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(grid, dp, n, m, 0, 0);
    }
};

class Solution {
public:
    // Function to find the minimum path sum recursively with memoization
    int minimumPathSumUtil(int i, int j, vector<vector<int>>& triangle, int n,
                           vector<vector<int>>& dp) {
        // If the result for this cell is already calculated, return it
        if (dp[i][j] != -1)
            return dp[i][j];

        // If we're at the bottom row, return the value of the current cell
        if (i == n - 1)
            return triangle[i][j];

        // Calculate the sum of two possible paths: going down and going
        // diagonally
        int down =
            triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp);
        int diagonal =
            triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp);

        // Store the minimum of the two paths in the dp table and return it
        return dp[i][j] = min(down, diagonal);
    }

    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
         vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return minimumPathSumUtil(0, 0, triangle, n, dp);
    }
};
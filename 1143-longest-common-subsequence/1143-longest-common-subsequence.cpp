class Solution {
public:
    int solve(int i1, int i2, int n1, int n2, string& t1, string& t2, vector<vector<int>>& dp) {
        // Base case: If either string is exhausted
        if (i1 == n1 || i2 == n2) {
            return 0;
        }

        // Return the result if already computed
        if (dp[i1][i2] != -1) {
            return dp[i1][i2];
        }

        // If characters match, take it and move to the next character in both strings
        if (t1[i1] == t2[i2]) {
            dp[i1][i2] = 1 + solve(i1 + 1, i2 + 1, n1, n2, t1, t2, dp);
        } else {
            // Otherwise, skip one character from either string and take the maximum result
            int skipT1 = solve(i1 + 1, i2, n1, n2, t1, t2, dp);
            int skipT2 = solve(i1, i2 + 1, n1, n2, t1, t2, dp);
            dp[i1][i2] = max(skipT1, skipT2);
        }

        return dp[i1][i2];
    }

    int longestCommonSubsequence(string t1, string t2) {
        int n1 = t1.size();
        int n2 = t2.size();

        // Initialize memoization array
        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        // Start the recursion
        return solve(0, 0, n1, n2, t1, t2, dp);
    }
};

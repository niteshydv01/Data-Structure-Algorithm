class Solution {
public:
    int solve(int n, string &s, string &s1, vector<vector<int>> &dp, int i, int j) {
        if (i >= n || j >= n) return 0;  // Base case: Out of bounds

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s1[j]) {  // If characters match, move diagonally
            dp[i][j] = 1 + solve(n, s, s1, dp, i + 1, j + 1);
        } else {  // Otherwise, move in either direction
            dp[i][j] = max(solve(n, s, s1, dp, i + 1, j), solve(n, s, s1, dp, i, j + 1));
        }
        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(), s1.end());  // Correct way to reverse string

        vector<vector<int>> dp(n, vector<int>(n, -1));  // Use 2D DP table
        return solve(n, s, s1, dp, 0, 0);
    }
};

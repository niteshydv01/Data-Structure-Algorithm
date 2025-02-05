class Solution {
public:
    // Function to calculate the length of the Longest Common Subsequence (LCS)
    int lcs(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);  // Use 1D DP arrays

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;  // Move current row to previous
        }
        return prev[m];  // Final result stored in last element
    }

    // Function to calculate the length of the Longest Palindromic Subsequence (LPS)
    int longestPalindromeSubsequence(string s) {
        string t = s;             // Original string
        reverse(t.begin(), t.end());  // Reversed string
        return lcs(s, t);
    }

    // Function to calculate the minimum insertions to make the string a palindrome
    int minInsertions(string s) {
        int n = s.size();
        int lps = longestPalindromeSubsequence(s);
        return n - lps;
    }
};

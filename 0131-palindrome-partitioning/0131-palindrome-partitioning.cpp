class Solution {
public:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    // Recursive helper function for backtracking
    void solve(vector<vector<string>>& ans, vector<string>& temp, string& s, int start) {
        if (start >= s.size()) {  // If the starting index reaches the end of the string
            ans.push_back(temp);  // Add the current partition to the answer
            return;
        }

        // Explore all possible partitions
        for (int end = start; end < s.size(); end++) {
            // Check if the current substring is a palindrome
            if (isPalindrome(s, start, end)) {
                temp.push_back(s.substr(start, end - start + 1));  // Add the palindrome substring
                solve(ans, temp, s, end + 1);  // Recur to partition the remaining substring
                temp.pop_back();  // Backtrack to try other partitions
            }
        }
    }

    // Main function
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans, temp, s, 0);  // Call the recursive function
        return ans;
    }
};

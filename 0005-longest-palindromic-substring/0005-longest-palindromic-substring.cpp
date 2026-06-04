class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n <= 1) return s;

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {

            // Odd length palindrome
            int l = i;
            int r = i;

            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;

                if (len > maxLen) {
                    maxLen = len;
                    start = l;
                }

                l--;
                r++;
            }

            // Even length palindrome
            l = i;
            r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;

                if (len > maxLen) {
                    maxLen = len;
                    start = l;
                }

                l--;
                r++;
            }
        }

        return s.substr(start, maxLen);
    }
};
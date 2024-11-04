class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        // If needle is empty, return 0
        if (m == 0) {
            return 0;
        }

        // Loop through haystack to find the starting index of the needle
        for (int i = 0; i <= n - m; i++) {
            bool found = true;

            // Check if needle matches the substring starting at index i
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }

            // If a full match was found, return the starting index
            if (found) {
                return i;
            }
        }
        
        // If needle is not found in haystack, return -1
        return -1;
    }
};

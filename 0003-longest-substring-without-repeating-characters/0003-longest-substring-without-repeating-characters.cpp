#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet; // To store unique characters in the current window
        int maxLength = 0;
        int left = 0; // Left pointer of the window
        
        // Right pointer iterates through the string
        for (int right = 0; right < s.size(); right++) {
            // If the character is already in the set, shrink the window
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]); // Remove the leftmost character
                left++; // Move the left pointer to the right
            }
            
            // Add the current character to the set
            charSet.insert(s[right]);
            
            // Update the maximum length of the substring
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

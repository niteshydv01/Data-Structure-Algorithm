class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need, window;

        // Frequency of characters in t
        for (char c : t)
            need[c]++;

        int required = need.size(); // Number of unique characters needed
        int formed = 0;             // Number of unique characters currently satisfied

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];
            window[c]++;

            // If current character reaches required frequency
            if (need.count(c) && window[c] == need[c])
                formed++;

            // Try shrinking
            while (formed == required) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char ch = s[left];

                window[ch]--;

                // Window no longer satisfies requirement
                if (need.count(ch) && window[ch] < need[ch])
                    formed--;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
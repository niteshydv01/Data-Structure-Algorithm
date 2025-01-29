class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int maxFreq = 0, ans = 0;
        int i = 0;

        for (int j = 0; j < s.size(); j++) {
            freq[s[j]]++;
            maxFreq = max(maxFreq, freq[s[j]]);

            while ((j - i + 1) - maxFreq > k) {
                freq[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
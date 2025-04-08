class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> freq;

            // Single loop to build frequency and calculate beauty
            for (int j = i; j < s.size(); j++) {
                freq[s[j]]++;  // update frequency for current substring s[i..j]

                // Convert map to vector
                vector<pair<char, int>> vec(freq.begin(), freq.end());

                // Sort vector in descending order of frequency
                sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
                    return a.second > b.second;
                });

                // Now max = vec[0].second, min = last element's second
                int maxFreq = vec[0].second;
                int minFreq = vec.back().second;

                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};

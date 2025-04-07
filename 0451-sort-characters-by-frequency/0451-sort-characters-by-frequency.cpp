class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> x;

        // Step 1: Count frequency of each character
        for (int i = 0; i < s.size(); i++) {
            x[s[i]]++;
        }

        // Step 2: Convert map to vector of pairs (char, freq)
        vector<pair<char, int>> vec(x.begin(), x.end());

        // Step 3: Sort the vector by frequency in descending order
        sort(vec.begin(), vec.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });

        // Step 4: Build the result string
        string result = "";
        for (auto& p : vec) {
            for(int i=0;i<p.second;i++){
                result+=p.first;
            }
        }

        return result;
    }
};

class Solution {
public:
    int romanToInt(string s) {
         unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
                // Subtractive case
                total -= roman[s[i]];
            } else {
                // Normal case
                total += roman[s[i]];
            }
        }
        
        return total;
    }
};
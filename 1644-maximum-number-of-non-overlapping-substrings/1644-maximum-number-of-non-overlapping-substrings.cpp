class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> start(26, n), end(26, -1);
        
        // Step 1: Record the first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            start[s[i] - 'a'] = min(start[s[i] - 'a'], i);
            end[s[i] - 'a'] = max(end[s[i] - 'a'], i);
        }

        // Step 2: Generate valid intervals
        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; ++i) {
            if (start[i] == n) continue; // character not in string
            int l = start[i];
            int r = end[i];
            bool valid = true;
            
            // Expand the interval to include all chars in range
            for (int j = l; j <= r; ++j) {
                int c = s[j] - 'a';
                if (start[c] < l) {
                    l = start[c];
                    j = l - 1; // restart from new l
                    valid = false; // need to validate again
                }
                if (end[c] > r) {
                    r = end[c];
                    j = l - 1; // restart from new l
                    valid = false;
                }
            }

            // After expansion, recheck it's valid
            valid = true;
            for (int j = l; j <= r; ++j) {
                int c = s[j] - 'a';
                if (start[c] < l || end[c] > r) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                intervals.emplace_back(l, r);
            }
        }

        // Step 3: Sort intervals by end to pick non-overlapping substrings greedily
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        // Step 4: Greedily select non-overlapping substrings
        vector<string> res;
        int lastEnd = -1;
        for (auto &[l, r] : intervals) {
            if (l > lastEnd) {
                res.push_back(s.substr(l, r - l + 1));
                lastEnd = r;
            }
        }

        return res;
    }
};

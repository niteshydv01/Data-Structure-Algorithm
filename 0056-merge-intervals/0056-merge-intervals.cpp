class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.empty()) return ans;

        // Step 1: Sort the intervals by their start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Initialize start and end with the first interval
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval overlaps with the previous one, merge them
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } else {
                // If it doesn't overlap, push the previous interval to the result
                ans.push_back({start, end});
                // Update start and end to the current interval
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        // Push the last interval
        ans.push_back({start, end});
        return ans;
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;

        // Step 1: Sort intervals by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];  // Sort by end time
        });

        int ans = 0;
        int end = intervals[0][1];  // Store the end time of the last non-overlapping interval

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {  
                // Overlapping interval found, so we must remove one
                ans++;
            } else {
                // No overlap, update end to the new interval's end
                end = intervals[i][1];
            }
        }
        return ans;
    }
};

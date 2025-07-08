class Solution {
public:
    int dfs(int i, int k, vector<vector<int>>& events, vector<vector<int>>& dp) {
        if (i == events.size() || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        // Option 1: skip this event
        int notTake = dfs(i + 1, k, events, dp);

        // Option 2: take this event
        // Binary search to find next non-overlapping event
        int l = i + 1, r = events.size(), next = events.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (events[m][0] > events[i][1]) {
                r = m;
                next = m;
            } else {
                l = m + 1;
            }
        }

        int take = events[i][2] + dfs(next, k - 1, events, dp);

        return dp[i][k] = max(take, notTake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // sort by start time
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return dfs(0, k, events, dp);
    }
};

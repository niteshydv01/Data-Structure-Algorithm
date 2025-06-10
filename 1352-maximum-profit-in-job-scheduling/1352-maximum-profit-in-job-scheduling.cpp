class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1]; 
             });

        vector<int> dp(n, 0);
        vector<int> endTimes(n, 0);

        dp[0] = jobs[0][2];
        endTimes[0] = jobs[0][1];

        for (int i = 1; i < n; ++i) {
            int includeProfit = jobs[i][2];
            int low = 0, high = i - 1;
            int lastNonConflict = -1;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (jobs[mid][1] <= jobs[i][0]) {
                    lastNonConflict = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (lastNonConflict != -1) {
                includeProfit += dp[lastNonConflict];
            }

            dp[i] = max(dp[i - 1], includeProfit);
            endTimes[i] = jobs[i][1];
        }

        return dp[n - 1];
    }
};

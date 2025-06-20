class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int mincost = INT_MAX;

        for (int ind = i; ind <= j; ind++) {
            int cost = (cuts[j + 1] - cuts[i - 1]) +
                        solve(i, ind - 1, cuts, dp) +
                        solve(ind + 1, j, cuts, dp);

            mincost = min(mincost, cost);
        }

        return dp[i][j] = mincost;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));
        return solve(1, c, cuts, dp);  // Use cuts[1] to cuts[c]
    }
};

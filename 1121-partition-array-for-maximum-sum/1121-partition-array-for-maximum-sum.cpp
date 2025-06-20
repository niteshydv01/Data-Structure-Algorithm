class Solution {
public:
    int solve(int ind, vector<int>& arr, int n, int k, vector<int>& dp) {
        if (ind == n) return 0;
        if (dp[ind] != -1) return dp[ind];

        int len = 0;
        int maxans = INT_MIN;
        int maxelement = INT_MIN;

        for (int i = ind; i < min(n, ind + k); i++) {
            len++;
            maxelement = max(maxelement, arr[i]);
            int sum = maxelement * len;
            int cost = sum + solve(i + 1, arr, n, k, dp);
            maxans = max(maxans, cost);
        }

        return dp[ind] = maxans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, arr, n, k, dp);
    }
};

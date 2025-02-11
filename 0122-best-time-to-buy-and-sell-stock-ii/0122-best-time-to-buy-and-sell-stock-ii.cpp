class Solution {
public:
    long getAns(vector<int>& Arr, int ind, int buy, int n, vector<vector<long>>& dp) {
        // Base case: When we reach the end of the array, there are no more
        // decisions to make.
        if (ind == n) {
            return 0;
        }

        // If the result for this state has already been calculated, return it
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }

        long profit = 0;

        if (buy == 0) { // We can buy the stock
            profit = max(0 + getAns(Arr, ind + 1, 0, n, dp),
                         -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
        }

        if (buy == 1) { // We can sell the stock
            profit = max(0 + getAns(Arr, ind + 1, 1, n, dp),
                         Arr[ind] + getAns(Arr, ind + 1, 0, n, dp));
        }

        // Store the calculated profit in the DP table and return it
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n, vector<long>(2, -1));

        if (n == 0) {
            return 0;
        }

        long ans = getAns(prices, 0, 0, n, dp);
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    // large negative sentinel for invalid/uncomputed states
    static constexpr ll NEG = LLONG_MIN / 4;

    ll getAns(const vector<int>& prices, int n, int ind, int state, int cap,
              vector<vector<vector<ll>>>& dp) {
        // If we've exhausted days:
        // - neutral (state==0) -> profit 0
        // - holding (long/short) -> invalid (can't finish with open position)
        if (ind == n)
            return (state == 0) ? 0LL : NEG;

        // If no transactions left:
        // - only neutral is valid (0 profit), holding is invalid
        if (cap == 0)
            return (state == 0) ? 0LL : NEG;

        ll &res = dp[ind][state][cap];
        if (res != NEG) return res; // memoized

        res = NEG;
        if (state == 0) { // neutral: can skip, open long, or open short
            res = max(res, getAns(prices, n, ind + 1, 0, cap, dp));                         // skip
            res = max(res, - (ll)prices[ind] + getAns(prices, n, ind + 1, 1, cap, dp));      // open long (buy)
            res = max(res,   (ll)prices[ind] + getAns(prices, n, ind + 1, 2, cap, dp));      // open short (sell first)
        }
        else if (state == 1) { // holding long: hold or close (sell)
            res = max(res, getAns(prices, n, ind + 1, 1, cap, dp));                         // hold long
            res = max(res,  (ll)prices[ind] + getAns(prices, n, ind + 1, 0, cap - 1, dp));   // close long -> consumes 1 transaction
        }
        else { // state == 2, holding short: hold or close (buy back)
            res = max(res, getAns(prices, n, ind + 1, 2, cap, dp));                         // hold short
            res = max(res, - (ll)prices[ind] + getAns(prices, n, ind + 1, 0, cap - 1, dp));  // close short -> consumes 1 transaction
        }

        return res;
    }




    long long maximumProfit(vector<int>& prices, int k) {
      int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // dp[ind][state][cap] initialized to NEG (means uncomputed)
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(3, vector<ll>(k + 1, NEG)));

        ll ans = getAns(prices, n, 0, 0, k, dp); // start neutral at day 0 with k transactions
        // answer should be >= 0 (we can always do nothing), clamp to 0 for safety
        return max(0LL, ans);
    }
};
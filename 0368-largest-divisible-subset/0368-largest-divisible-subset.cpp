/*class Solution {
public:
    vector<int> bestSubset;

    void solve(vector<int>& temp, int index, vector<int>& nums) {
        if (temp.size() > bestSubset.size()) {
            bestSubset = temp;
        }

        for (int j = index; j < nums.size(); ++j) {
            if (temp.empty() || nums[j] % temp.back() == 0) {
                temp.push_back(nums[j]);
                solve(temp, j + 1, nums);
                temp.pop_back();
            }
        }
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(temp, 0, nums);
        return bestSubset;
    }
};*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);         // dp[i] = size of largest subset ending at nums[i]
        vector<int> prev(n, -1);      // prev[i] = previous index in the subset chain

        int maxLen = 1, lastIndex = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the largest subset
        vector<int> result;
        while (lastIndex != -1) {
            result.push_back(nums[lastIndex]);
            lastIndex = prev[lastIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


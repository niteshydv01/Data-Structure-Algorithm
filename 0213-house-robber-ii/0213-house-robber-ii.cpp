class Solution {
public:
    // Recursive function with memoization
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) {
            return 0; // Base case: No more houses to rob
        }
        
        if (dp[i] != -1) {
            return dp[i]; // Return cached result
        }
        
        int includeCurrent = nums[i] + solve(nums, i + 2, dp);  // Rob current house
        int excludeCurrent = solve(nums, i + 1, dp);  // Skip current house
        
        dp[i] = max(includeCurrent, excludeCurrent);  // Take the best option
        return dp[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  // Base case: Only one house
        
        vector<int> dp1(n, -1);  // Memoization for Case 1
        vector<int> dp2(n, -1);  // Memoization for Case 2
        
        // Case 1: Rob from 0 to n-2 (excluding last house)
        vector<int> nums1(nums.begin(), nums.end() - 1);
        int case1 = solve(nums1, 0, dp1);
        
        // Case 2: Rob from 1 to n-1 (excluding first house)
        vector<int> nums2(nums.begin() + 1, nums.end());
        int case2 = solve(nums2, 0, dp2);
        
        return max(case1, case2);
    }
};


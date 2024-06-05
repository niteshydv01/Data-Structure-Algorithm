class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& memo) {
        if (i >= nums.size()) {
            return 0;
        }
        
        if (memo[i] != -1) {
            return memo[i];
        }
        
        int includeCurrent = nums[i] + solve(nums, i + 2, memo);
        int excludeCurrent = solve(nums, i + 1, memo);
        
        memo[i] = max(includeCurrent, excludeCurrent);
        return memo[i];
    }
    
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(nums, 0, memo);
    }
};

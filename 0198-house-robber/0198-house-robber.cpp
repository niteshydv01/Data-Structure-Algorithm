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
        
       return memo[i] = max(includeCurrent, excludeCurrent);
        //return memo[i];
    }
    
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(nums, 0, memo);
    }
 
    /*int solve(vector<int>& nums, int n, int i, int sum) {
        if (i >= n) {
            return sum;
        }
        
        return max(solve(nums, n, i + 2, sum + nums[i]), solve(nums, n, i + 1, sum));
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, n, 0, 0);
    }*/


};

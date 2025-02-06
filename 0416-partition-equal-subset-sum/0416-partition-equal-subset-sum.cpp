/*class Solution {
public:
    bool solve(int n, vector<int>& arr, int target, int i, vector<vector<int>> &dp) {
        if(target==0)return true;
        if(i==n && target<0)return false;
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool take=false;
        if(arr[i]<=target){
            take=solve(n,arr,target-arr[i],i+1,dp);
        }
        bool nottake=solve(n,arr,target,i+1,dp);

        dp[i][target]=take || nottake;

        return dp[i][target];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int target;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum/2 !=0){
            return false;
        }
        else {
            target=sum/2;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));  // 
        return solve(n, nums, target, 0, dp);
        
    }
};*/
#include <vector>

using namespace std;

class Solution {
public:
    bool solve(int n, vector<int>& arr, int target, int i, vector<vector<int>> &dp) {
        if (target == 0) return true;  // Found a valid subset
        if (i == n) return false;  // Reached the end of the array without finding subset

        if (dp[i][target] != -1) return dp[i][target];  // Use memoization

        // Take current element if it does not exceed the target
        bool take = false;
        if (arr[i] <= target) {  // ✅ Fixed: `<=` instead of `<`
            take = solve(n, arr, target - arr[i], i + 1, dp);
        }

        // Skip current element
        bool nottake = solve(n, arr, target, i + 1, dp);

        return dp[i][target] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        // Compute total sum
        for (int num : nums) {
            sum += num;
        }

        // If sum is odd, it's impossible to split into two equal subsets
        if (sum % 2 != 0) return false;  // ✅ Fixed: Correctly check if sum is odd

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));  

        return solve(n, nums, target, 0, dp);
    }
};

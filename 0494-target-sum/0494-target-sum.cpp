class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int n = nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        int diff=sum-target;

        // Check if it's possible to achieve the target
        if (diff<0|| diff%2!=0) return 0;

        diff/=2;


//dp[j][sum] represents the # of ways to get sum using the first j elements of nums
        int dp[21][2001]={{0}};

        // There's one way to get a sum of 0 without selecting any element
        dp[0][0] = 1;

        for (int j=1; j <= n; j++) {
            for (int sum=0; sum <= diff; sum++) {
                dp[j][sum] = dp[j-1][sum]; 

                if (sum >= nums[j-1]) 
                    dp[j][sum]+=dp[j-1][sum-nums[j-1]];
            }
        }
        return dp[n][diff];
    }
};
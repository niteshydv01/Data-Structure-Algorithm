class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;  // Initialize maxSum to a very small number
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if(sum > maxSum) {
                maxSum = sum;
            }
            
            if(sum < 0) {
                sum = 0;
            }
        }
        
        return maxSum;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        /*int n = nums.size();
        int i = 0;
        int j = n - 1;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            int leftsum = 0;
            for (int k = 0; k < mid; k++) {
                leftsum += nums[k];
            }

            int rightsum = 0;
            for (int k = mid + 1; k < n; k++) { 
                rightsum += nums[k];
            }

            if (leftsum == rightsum) {
                return mid;
            }
            else if (leftsum < rightsum) {
                i = mid + 1; 
            } 
            else {
                j = mid - 1; 
            }
        }
        return -1;*/
           int totalSum = 0;
        for (int num : nums) totalSum += num;  

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) {
                return i;  
            }
            leftSum += nums[i];
        }
        return -1;  
    }
};

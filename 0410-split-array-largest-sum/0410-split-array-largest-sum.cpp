class Solution {
public:
    bool possible(vector<int> nums, int n, int cap, int part) {
        int currPart = 1;
        int subArrSum = 0;

        for(int i=0; i<n; i++) {
            if(subArrSum + nums[i] <= cap) {
                // Insert element to current subarray
                subArrSum += nums[i];
            } 
            else {
                // Insert element to next subarray
                currPart++;
                subArrSum = nums[i];
            }
        }
        return (currPart <= part);
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while(low <= high) {
            int mid = (low + high) / 2;

            if(possible(nums, n, mid, k)) {
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
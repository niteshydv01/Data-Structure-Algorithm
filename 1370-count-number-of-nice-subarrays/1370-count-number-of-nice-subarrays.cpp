class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    
private:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0; // Edge case: No valid subarrays

        int left = 0, count = 0, oddCount = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 == 1) { // If it's an odd number, decrement k
                k--;
            }

            while (k < 0) { // If too many odds, shrink the window
                if (nums[left] % 2 == 1) {
                    k++;
                }
                left++;
            }

            count += (right - left + 1); // Count all valid subarrays
        }

        return count;
    }
};


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) return true;

            // Handle duplicates: shrink the search space
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++;
                e--;
            }
            // Left half is sorted
            else if (nums[s] <= nums[mid]) {
                if (nums[s] <= target && target < nums[mid]) {
                    e = mid - 1;  // Search in left half
                } else {
                    s = mid + 1;  // Search in right half
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[e]) {
                    s = mid + 1;  // Search in right half
                } else {
                    e = mid - 1;  // Search in left half
                }
            }
        }
        return false;
    }
};

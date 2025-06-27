class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;
        int mid;

        while (s <= e) {
            mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                int left = mid, right = mid;

                // Expand left
                while (left > 0 && nums[left - 1] == target) left--;

                // Expand right
                while (right < n - 1 && nums[right + 1] == target) right++;

                return {left, right};
            }

            if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return {-1, -1}; // target not found
    }
};


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;

        while (s < e) {  // Notice: changed condition from s <= e to s < e
            int mid = s + (e - s) / 2;

            if (nums[mid] < nums[mid + 1]) {  // Move right if increasing
                s = mid + 1;
            } else {  // Move left if decreasing
                e = mid;
            }
        }
        return s;  // or return e (both will be the same)
    }
};

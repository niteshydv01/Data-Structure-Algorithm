/*class Solution {
public:
    int binarysearch(int s, int e, vector<int>& nums) {
        if (s == e) {
            // Only one element left, return it
            return nums[s];
        }
        
        int mid = s + (e - s) / 2;
        
        // Check if mid is the single element
        if (mid > 0 && mid < nums.size() - 1 && nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) {
            return nums[mid];
        }
        
        // Check the halves to determine where to search
        if ((mid % 2 == 0 && nums[mid] == nums[mid+1]) || (mid % 2 == 1 && nums[mid] == nums[mid-1])) {
            // Single element is in the right half
            return binarysearch(mid + 1, e, nums);
        } else {
            // Single element is in the left half
            return binarysearch(s, mid - 1, nums);
        }
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        return binarysearch(0, n - 1, nums);
    }
};
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        
        while (s < e) {
            int mid = s + (e - s) / 2;
            
            // Ensure we always compare mid with its pair
            if (mid % 2 == 1) {
                mid--; // Make mid even, ensuring it's the start of a pair
            }
            
            // Check if this pair is broken
            if (nums[mid] == nums[mid + 1]) {
                // If pair is valid, the single element must be in the right half
                s = mid + 2;
            } else {
                // If pair is invalid, the single element must be in the left half
                e = mid;
            }
        }
        
        // At the end of the loop, s == e, pointing to the single element
        return nums[s];
    }
};

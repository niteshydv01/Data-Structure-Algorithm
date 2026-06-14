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
            
            
            if (mid % 2 == 1) {
                mid--; 
            }
            // if(nums[mid]!=nums[mid+1]){
            //     return nums[mid];
            // }
            
            
            if (nums[mid] == nums[mid + 1]) {
                
                s = mid + 2;
            } else {
                
                e = mid;
            }
        }
        
      
        return nums[e];
    }
};

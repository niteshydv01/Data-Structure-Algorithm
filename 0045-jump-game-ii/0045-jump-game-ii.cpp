/*class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;  // No jump needed if already at the last index

        int i = 0; 
        int currreach = 0;  // Current farthest reachable index
        int maxd = nums[i]; // Maximum distance that can be reached
        int count = 0;      // Number of jumps
        
        while (i < n - 1) {
            count++;  // Taking a jump
            
            int bestIndex = i;  // Track the best jump
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                if (nums[i + j] + j > maxd) {
                    maxd = nums[i + j] + j;
                    bestIndex = i + j;
                }
            }
            
            if (bestIndex == i) return -1;  // If stuck, return -1 (should not happen for valid input)
            
            i = bestIndex;  // Move to the best reachable index
            
            if (i >= n - 1) return count;  // If reached the last index, return jumps
        }
        
        return count;
    }
};*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;  // No jump needed if already at the last index

        int count = 0;       // Number of jumps
        int currreach = 0;   // End of the current jump range
        int maxd = 0;        // Farthest index that can be reached

        for (int i = 0; i < n - 1; i++) {
            maxd = max(maxd, i + nums[i]);  // Update the farthest reachable index
            
            if (i == currreach) {  // When we reach the end of the current jump range
                count++; 
                currreach = maxd;  // Move to the next farthest index
                
                if (currreach >= n - 1) return count;  // If we reached or exceeded last index, return count
            }
        }
        
        return count;
    }
};

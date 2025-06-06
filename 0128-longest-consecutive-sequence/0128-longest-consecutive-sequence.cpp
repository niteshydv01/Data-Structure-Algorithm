class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int current = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                // skip duplicates
                continue;
            } else if (nums[i] == nums[i - 1] + 1) {
                current++;
                longest = max(longest, current);
            } else {
                // reset current streak
                current = 1;
            }
        }

        return longest;
        
    }
};
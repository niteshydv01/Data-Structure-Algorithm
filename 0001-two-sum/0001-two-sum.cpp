class Solution {
public:
    vector<int> twoSumHelper(vector<int>& nums, int target, int i) {
        
        if (i >= nums.size()) return {};

  
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};  
            }
        }

        
        return twoSumHelper(nums, target, i + 1);
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        return twoSumHelper(nums, target, 0);
    }
};

    



 
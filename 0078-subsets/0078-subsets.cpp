#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& result, vector<int>& subset, int i, vector<int>& nums) {
        if (i == nums.size()) {
            result.push_back(subset);
            return;
        }
        
        // Include nums[i] in the current subset and recurse
        subset.push_back(nums[i]);
        solve(result, subset, i + 1, nums);
        
        // Exclude nums[i] from the current subset and recurse
        subset.pop_back();
        solve(result, subset, i + 1, nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        solve(result, subset, 0, nums);
        return result;
    }
};

/*private:
    void generateSubsets(const vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(subset);
        
        // Generate subsets starting from the current index
        for (int i = index; i < nums.size(); ++i) {
            // Include nums[i] in the current subset
            subset.push_back(nums[i]);
            
            // Recursively generate subsets starting from the next index
            generateSubsets(nums, i + 1, subset, result);
            
            // Exclude nums[i] from the current subset (backtrack)
            subset.pop_back();
        }
    }*/

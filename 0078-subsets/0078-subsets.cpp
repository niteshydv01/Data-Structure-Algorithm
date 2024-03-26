#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        generateSubsets(nums, 0, subset, result);
        return result;
    }

private:
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
    }
};

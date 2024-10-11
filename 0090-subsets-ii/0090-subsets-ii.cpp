class Solution {
public:
    // Helper function to generate subsets
    void solve(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int size, int i) {
        // Base condition: if we've processed all elements
        if (i >= size) {
            ans.push_back(temp); // Add the current subset to the result
            return;
        }

        // Include the current element and move to the next element
        temp.push_back(nums[i]);
        solve(ans, temp, nums, size, i + 1);

        // Backtrack by removing the last added element
        temp.pop_back();

        // Skip the current element and move to the next element
        // Avoid duplicates: skip the next elements if they are the same as the current one
        while (i + 1 < size && nums[i] == nums[i + 1]) {
            i++;
        }
        solve(ans, temp, nums, size, i + 1);
    }

    // Main function to return all subsets without duplicates
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        // Sort the nums array to handle duplicates easily
        sort(nums.begin(), nums.end());

        // Call the helper function
        solve(ans, temp, nums, nums.size(), 0);
        return ans;
    }
};

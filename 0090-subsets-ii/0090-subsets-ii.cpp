class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums,
               int size, int i) {

        if (i >= size) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(ans, temp, nums, size, i + 1);

        temp.pop_back();

        while (i + 1 < size && nums[i] == nums[i + 1]) {
            i++;
        }
        solve(ans, temp, nums, size, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        solve(ans, temp, nums, nums.size(), 0);
        return ans;
    }
};

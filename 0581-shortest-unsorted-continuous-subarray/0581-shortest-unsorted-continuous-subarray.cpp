class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int start = -1, end = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != sorted[i]) {
                if (start == -1) start = i;
                end = i;
            }
        }

        return (start == -1) ? 0 : (end - start + 1);
    }
};

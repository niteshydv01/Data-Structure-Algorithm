class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int z = 0; /

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[i - z] = nums[i]; 
            } else {
                z++; 
            }
        }

        for (int i = n - z; i < n; i++) {
            nums[i] = 0;
        }
    }
};

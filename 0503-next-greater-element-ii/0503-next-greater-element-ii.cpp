class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1); // Initialize with -1
        stack<int> s; // Stack to store indices

        // Iterate twice to handle the circular nature
        for (int i = 0; i < 2 * n; ++i) {
            int current_num = nums[i % n];

            // While stack is not empty and the current number is greater than the number
            // at the index on top of the stack, we've found the next greater element.
            while (!s.empty() && nums[s.top()] < current_num) {
                result[s.top()] = current_num;
                s.pop();
            }

            // In the first pass, push the current index onto the stack
            if (i < n) {
                s.push(i);
            }
        }
        
        return result;
    }
};
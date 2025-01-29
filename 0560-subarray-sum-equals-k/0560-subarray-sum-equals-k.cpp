class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq;
        int count = 0, prefixSum = 0;

        // Initialize prefix sum frequency map
        prefixSumFreq[0] = 1;

        for (int num : nums) {
            prefixSum += num;

            // Check if there is a subarray sum that equals `k`
            if (prefixSumFreq.find(prefixSum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[prefixSum - k];
            }

            // Store the current prefix sum frequency
            prefixSumFreq[prefixSum]++;
        }

        return count;
    }
};
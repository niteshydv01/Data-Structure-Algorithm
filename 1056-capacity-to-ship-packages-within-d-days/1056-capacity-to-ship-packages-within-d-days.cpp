class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());  // Minimum capacity should be at least max weight
        int right = accumulate(weights.begin(), weights.end(), 0);  // Maximum capacity is sum of all weights
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = 1;  // Start with one day
            int sum = 0;

            for (int i = 0; i < weights.size(); i++) {
                sum += weights[i];

                if (sum > mid) {
                    count++;  // New day required
                    i--;  // Reprocess this weight in the next day's shipment
                    sum = 0;  // Reset sum for the new day
                }
            }

            if (count <= days) {  // Valid capacity, try to minimize
                ans = mid;
                right = mid - 1;
            } else {  // Too few days, increase capacity
                left = mid + 1;
            }
        }

        return ans;
    }
};

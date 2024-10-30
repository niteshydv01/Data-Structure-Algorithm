/*#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> ans;
        
        // Iterate over each starting index of the window
        for (int i = 0; i <= nums.size() - k; i++) {
            int maxi = INT_MIN;

            // Find the maximum in the current window of size k
            for (int j = i; j < i + k; j++) {
                maxi = std::max(maxi, nums[j]);
            }

            ans.push_back(maxi);
        }

        return ans;
    }
};*/
#include <vector>
#include <deque>
#include <algorithm>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> ans;
        std::deque<int> dq;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements that are out of the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // Remove elements from the back of the deque if they are smaller than the current element
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(i);

            // Add the maximum element of the window to the result
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        
        return ans;
    }
};


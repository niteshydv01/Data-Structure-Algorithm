// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         queue<int> q;

//         for(int x : nums) {
//             q.push(x);
//         }

//         vector<int> ans;

//         while(q.size() >= k) {
//             int maxi = INT_MIN;

//             queue<int> temp = q;

//             for(int i = 0; i < k; i++) {
//                 maxi = max(maxi, temp.front());
//                 temp.pop();
//             }

//             ans.push_back(maxi);

//             q.pop(); 
//         }

//         return ans;
//     }
// };

// 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            // Remove indices outside current window
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Window complete
            if(i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
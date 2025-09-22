class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Find the position of x or the closest index
        int i = -1;
        for (int idx = 0; idx < arr.size(); idx++) {
            if (arr[idx] == x) {
                i = idx;
                break;
            }
        }

        // If x is not found, find closest index
        if (i == -1) {
            i = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            if (i > 0 && (i == arr.size() || abs(arr[i-1] - x) <= abs(arr[i] - x))) {
                i = i - 1;
            }
        }

        int left = i - 1;
        int right = i + 1;
        vector<int> ans;
        ans.push_back(arr[i]);

        // Expand until k elements are collected
        while (ans.size() < k) {
            if (left >= 0 && right < arr.size()) {
                if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                    ans.push_back(arr[left--]);
                } else {
                    ans.push_back(arr[right++]);
                }
            } else if (left >= 0) {
                ans.push_back(arr[left--]);
            } else {
                ans.push_back(arr[right++]);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

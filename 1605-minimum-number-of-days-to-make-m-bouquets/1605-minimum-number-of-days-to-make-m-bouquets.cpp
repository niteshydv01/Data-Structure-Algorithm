class Solution {
public:
    bool possible(vector<int>& arr, int day, int m, int k) {
        int cnt = 0, noOfB = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) {
                cnt++;
                if (cnt == k) {
                    noOfB++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return noOfB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL * m * k;
        if (total > bloomDay.size()) return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for (int day : bloomDay) {
            mini = min(mini, day);
            maxi = max(maxi, day);
        }

        int ans = -1;
        while (mini <= maxi) {
            int mid = mini + (maxi - mini) / 2;
            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                maxi = mid - 1;
            } else {
                mini = mid + 1;
            }
        }
        return ans;
    }
};

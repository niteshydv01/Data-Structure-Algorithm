class Solution {
public:
    struct cmp {
        bool operator()(const string &a, const string &b) {
            if (a.size() == b.size())
                return a < b;      // larger string gets higher priority
            return a.size() < b.size();
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, cmp> q;

        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }

        for (int i = 0; i < k - 1; i++) {
            q.pop();
        }

        return q.top();
    }
};
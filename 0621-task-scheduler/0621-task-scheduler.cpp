class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        int maxi = 0;
        int count = 0;
        for (int i = 0; i < tasks.size(); i++) {
            m[tasks[i]]++;
            maxi = max(maxi, m[tasks[i]]);
        }
        for (auto it : m) {
            if (it.second == maxi)
                count++;
        }
        int x = (maxi - 1) * n + count - 1 + maxi;
        int total = tasks.size();
        return total > x ? total : x;
    }

}
;
class Solution {
public:
    int count = 0; // to keep track of current permutation number
    string answer; // to store the final k-th permutation
    bool found = false;

    void permute(vector<int>& nums, vector<bool>& used, string& current, int k) {
        if (current.length() == nums.size()) {
            count++;
            if (count == k) {
                answer = current;
                found = true;
            }
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                current += to_string(nums[i]);
                permute(nums, used, current, k);
                if (found) return; // early stopping
                current.pop_back();
                used[i] = false;
            }
        }
    }

    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }

        vector<bool> used(n, false);
        string current = "";
        permute(nums, used, current, k);
        return answer;
    }


};
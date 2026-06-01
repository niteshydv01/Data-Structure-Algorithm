class Solution {
public:
    
    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void solve(int start, string &s,
               vector<string> &curr,
               vector<vector<string>> &ans) {

        if (start == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int end = start; end < s.size(); end++) {

            if (isPalindrome(s, start, end)) {

                curr.push_back(s.substr(start, end - start + 1));

                solve(end + 1, s, curr, ans);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> curr;

        solve(0, s, curr, ans);

        return ans;
    }
};
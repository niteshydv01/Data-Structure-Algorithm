class Solution {
public:
    void bt(int open, int close, int n, string str, vector<string> &ans) {
        if(open == close && open == n) {
            ans.push_back(str);
            return;
        }
        if(open < n) {
            str += "(";
            bt(open + 1, close, n, str, ans);
            str.pop_back();
        }
        if(close < open) {
            str += ")";
            bt(open, close + 1, n, str, ans);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        string str = "";
        vector<string> ans;
        bt(open, close, n, str, ans);
        return ans;
    }
};
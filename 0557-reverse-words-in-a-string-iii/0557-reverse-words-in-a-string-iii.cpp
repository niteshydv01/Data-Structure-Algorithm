class Solution {
public:
    string reverseWords(string s) {
        stack<char> stk;
        string ans;
        int i = 0;
        while (i < s.length()) {
            if (s[i] != ' ') {
                stk.push(s[i]);
            } else {
                while (!stk.empty()) {
                    ans += stk.top();
                    stk.pop();
                }
                ans += ' '; // Add space after each word
            }
            i++;
        }
        
        // Add the last word (if any) from the stack
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        
        return ans;
    }
};


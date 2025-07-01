/*class Solution {
public:
    bool ispalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    string shortestPalindrome(string s) {
        if (ispalindrome(s)) return s;

        int n = s.size();
        string prefix = "";

        for (int i = n - 1; i >= 0; i--) {
            string sub = s.substr(0, i);
            if (ispalindrome(s.substr(0, i + 1))) {
                prefix = s.substr(i + 1);
                break;
            }
        }

        reverse(prefix.begin(), prefix.end());
        return prefix + s;
    }
};*/
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string new_str = s + "#" + rev;
        int n = new_str.size();

        vector<int> lps(n, 0); // prefix function

        for (int i = 1; i < n; i++) {
            int len = lps[i - 1];
            while (len > 0 && new_str[i] != new_str[len]) {
                len = lps[len - 1];
            }
            if (new_str[i] == new_str[len]) {
                len++;
            }
            lps[i] = len;
        }

        int to_add = s.size() - lps[n - 1];
        string add = s.substr(lps[n - 1]);
        reverse(add.begin(), add.end());

        return add + s;
    }
};


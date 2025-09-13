class Solution {
public:
 
    bool issubstring(string a, string b) {
        int n = a.size(), m = b.size();
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && a[i + j] == b[j]) {
                j++;
            }
            if (j == m) return true;
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        if (b == "") return 0;

        string repeated = a;  
        int count = 1;

        while (true) {
            if (issubstring(repeated, b)) {
                return count;
            }
            repeated += a;
            count++;

          
            if (repeated.size() > b.size() + a.size() * 2)
                return -1;
        }
    }
};

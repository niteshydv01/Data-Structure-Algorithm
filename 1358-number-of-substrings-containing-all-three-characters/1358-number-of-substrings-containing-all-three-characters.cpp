/*class Solution {
public:
    bool check(int st, int l, string& s) {
        int x = 0, y = 0, z = 0;
        for (int i = st; i < st + l; i++) {
            if (s[i] == 'a') x++;
            else if (s[i] == 'b') y++;
            else if (s[i] == 'c') z++;
        }
        return (x > 0 && y > 0 && z > 0);
    }

    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.length();
        
        for (int l = 3; l <= n; l++) {  // minimum length to contain 'a', 'b', 'c' is 3
            for (int st = 0; st <= n - l; st++) {
                if (check(st, l, s)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
*/
class Solution {
public:
    bool check(int st, int l, string& s) {
        int x = 0, y = 0, z = 0;
        for (int i = st; i < st + l; i++) {
            if (s[i] == 'a') x++;
            if (s[i] == 'b') y++;
            if (s[i] == 'c') z++;
        }
        return x != 0 && y != 0 && z != 0;
    }
    
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.length();
        int x = 0, y = 0, z = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (s[right] == 'a') x++;
            if (s[right] == 'b') y++;
            if (s[right] == 'c') z++;

            while (x > 0 && y > 0 && z > 0) {
                count += n - right;
                if (s[left] == 'a') x--;
                if (s[left] == 'b') y--;
                if (s[left] == 'c') z--;
                left++;
            }
        }
        return count;
    }
};

/*class Solution {
public:
    string largestOddNumber(string num) {
        int ma = -1; // initialize with -1 to indicate no odd digit found
        for(int i = 0; i < num.size(); i++) {
            char x = num[i];
            if((x - '0') % 2 != 0) {
                ma = max(ma, x - '0');
            }
        }
        if(ma == -1) return ""; // no odd digit found
        string t = "";
        t += (ma + '0'); // convert back to character
        return t;
    }
};*/
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; --i) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};


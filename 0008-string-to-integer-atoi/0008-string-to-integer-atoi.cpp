class Solution {
public:
    int myAtoi(string s) {
    long long int r = 0;
    int neg = 1;
    bool ss = false, started = false;

    for (char c : s) {
        if (c == ' ' && !started && !ss) 
            continue;

        if ((c == '-' || c == '+') && !started && !ss) {
            neg = (c == '-') ? -1 : 1;
            ss = true;
            continue;
        }
        
        if (c >= '0' && c <= '9') {
            started = true;
            r = (r * 10) + (c - '0');

            if (r > INT_MAX) 
                return (neg == 1) ? INT_MAX : INT_MIN;
        } 
        else break;
    }
    
    return r * neg;
}

};
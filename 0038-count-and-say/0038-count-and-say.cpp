class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string prev = countAndSay(n - 1);  // Get previous term
        string result = "";
        int count = 1;
        
        for(int i = 1; i < prev.size(); i++) {
            if(prev[i] == prev[i - 1]) {
                count++;
            } else {
                result += to_string(count) + prev[i - 1];
                count = 1;
            }
        }
        
        // Append the last group
        result += to_string(count) + prev.back();
        
        return result;
    }
};

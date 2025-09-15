class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string current = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0'); // Build the multiplier
            } else if (ch == '[') {
                countStack.push(k);      // Save the multiplier
                stringStack.push(current); // Save the current string
                current = "";            // Reset current
                k = 0;                   // Reset multiplier
            } else if (ch == ']') {
                int repeat = countStack.top(); countStack.pop();
                string prev = stringStack.top(); stringStack.pop();
                string temp = "";
                for (int i = 0; i < repeat; i++) {
                    temp += current;
                }
                current = prev + temp;
            } else {
                current += ch; // Append characters to current
            }
        }

        return current;
    }
};

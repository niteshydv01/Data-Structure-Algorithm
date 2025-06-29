class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;   // count of unmatched '('
        int insertions = 0; // total insertions needed

        for (char c : s) {
            if (c == '(') {
                open++;  // we need a closing ')' later
            } else if (c == ')') {
                if (open > 0) {
                    open--;  // match found
                } else {
                    insertions++;  // no opening for this ')', insert one '('
                }
            }
        }

        // total insertions = unmatched ')' + unmatched '('
        return insertions + open;
    }
};

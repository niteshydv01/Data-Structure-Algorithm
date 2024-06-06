#include <vector>
#include <stack>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ans;
        std::stack<std::vector<int>> top;

        if (numRows == 0) return ans;
        
        // Initialize the first row
        std::vector<int> firstRow = {1};
        top.push(firstRow);
        ans.push_back(firstRow);
        
        while (ans.size() < numRows) {
            std::vector<int> current = top.top();
            top.pop();

            // Create the next row
            std::vector<int> nextRow(current.size() + 1, 1); // Initialize with 1s
            for (size_t j = 1; j < current.size(); ++j) {
                nextRow[j] = current[j - 1] + current[j];
            }
            
            top.push(nextRow);
            ans.push_back(nextRow);
        }
        
        return ans;
    }
};
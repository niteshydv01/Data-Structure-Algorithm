#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        vector<int> result;

        // Count occurrences of each element
        for (int num : nums) {
            mpp[num]++;
        }

        // Check for majority elements (appear more than n/3 times)
        for (auto& pair : mpp) {
            if (pair.second > n / 3) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};



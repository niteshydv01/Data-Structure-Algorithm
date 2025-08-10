class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater; 
        stack<int> s;

        
        for (int num : nums2) {
            while (!s.empty() && num > s.top()) {
                next_greater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

      
        while (!s.empty()) {
            next_greater[s.top()] = -1;
            s.pop();
        }

     
        vector<int> result;
        for (int num : nums1) {
            result.push_back(next_greater[num]);
        }

        return result;
    }
};
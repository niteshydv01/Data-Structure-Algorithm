class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> zero;
        vector<int> one;
        vector<int> two;
        vector<int> combined;
        for (int value : nums) {
            if (value == 0) {
                zero.push_back(value);
            } else if (value == 1) {
                one.push_back(value);
            } else {
                two.push_back(value);
            }
        }
        combined.insert(combined.end(), zero.begin(), zero.end());

        // Insert elements from vec2
        combined.insert(combined.end(), one.begin(), one.end());

        // Insert elements from vec3
        combined.insert(combined.end(), two.begin(), two.end());
        nums=combined;
        
    }
};
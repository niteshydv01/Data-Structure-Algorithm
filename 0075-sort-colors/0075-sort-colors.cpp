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
        for(int value:zero){
            combined.push_back(value);
        }
        for(int value:one){
            combined.push_back(value);
        }
        for(int value:two){
            combined.push_back(value);
        }



       
        nums=combined;
        
    }
};
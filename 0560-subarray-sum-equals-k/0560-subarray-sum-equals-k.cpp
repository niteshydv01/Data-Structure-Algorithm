class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int> x;

        x[0] = 1;

        int ans = 0;
        int prefixsum = 0;

        for(int i = 0; i < nums.size(); i++) {

            prefixsum += nums[i];

            if(x.find(prefixsum - k) != x.end()) {
                ans += x[prefixsum - k];
            }

            x[prefixsum]++;
        }

        return ans;
        
    }
};
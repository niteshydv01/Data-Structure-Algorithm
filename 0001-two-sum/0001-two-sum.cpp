class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int>x;
        for(int i =0;i<nums.size();i++){
            int c=target-nums[i];
            if(x.find(c)!=x.end()){
                return{x[c],i};
            }
            x[nums[i]]=i;
        }
        return {-1,-1};
        
    }
};
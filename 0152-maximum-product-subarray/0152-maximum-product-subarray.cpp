class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=0;
        int suf=0;
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(pre==0)pre=1;
            if(suf==0)suf=1;
            pre=pre*nums[i];
            suf=suf*nums[n-i-1];
            ans=max(ans,max(pre,suf));
        }
        return ans;
    }
};
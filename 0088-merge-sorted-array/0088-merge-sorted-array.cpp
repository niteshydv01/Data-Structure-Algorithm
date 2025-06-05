class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<nums1.size();i++){
            if(i+1<=m){
                continue;
            }
            else{
                nums1[i]=nums2[abs(m-i)];
            }
        }
        sort(nums1.begin(),nums1.end());
    }
};
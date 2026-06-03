class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>greater;

        stack<int>st;

        for(int i=0;i<nums2.size();i++){

            while(!st.empty() && nums2[i] > st.top()){
                greater[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        while (!st.empty()) {
            greater[st.top()] = -1;
            st.pop();
        }
        
        for(int i=0;i<nums1.size();i++){
            int x=greater[nums1[i]];
            nums1[i]=x;
        }
        return nums1;
        
    }
};
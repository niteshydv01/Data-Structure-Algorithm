// class Solution {
// public:
//     void solve(int i,int n,int tar,vector<int>& candidates,vector<int>&curr,vector<vector<int>>&ans){
//         if(tar==0){
//             ans.push_back(curr);
//             return;
//         }
//         if(i>=n || tar <0){
//             return 0;
//         }
//         curr.push_back(candiddates[i]);
//         solve(i+1,n,tar-candiddates[i],candidates,curr,ans);

//         curr.pop_back();

//         solve(i,n,tar-candiddates[i],candidates,curr,ans);
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<vector<int>>ans;
//         vector<int>curr;

//         solve(0,candidates.size(),target,candidates,curr,ans);
        
//     }
// };
class Solution {
public:

    void solve(int idx,
               vector<int>& candidates,
               int target,
               vector<int>& curr,
               vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
                continue;

            if(candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            solve(i+1,
                  candidates,
                  target-candidates[i],
                  curr,
                  ans);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0,candidates,target,curr,ans);

        return ans;
    }
};
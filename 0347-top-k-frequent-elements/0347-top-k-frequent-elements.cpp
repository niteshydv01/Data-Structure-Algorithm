class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        vector<pair<int,int>> freq;

        for(auto it : mp){
            freq.push_back({it.first, it.second});
        }

        sort(freq.begin(), freq.end(),
             [](pair<int,int>& a, pair<int,int>& b){
                 return a.second > b.second;
             });

        vector<int> ans;

        for(int i=0; i<k; i++){
            ans.push_back(freq[i].first);
        }

        return ans;
    }
};
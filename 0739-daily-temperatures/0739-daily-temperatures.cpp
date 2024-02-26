 class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk; //index-temp
        vector<int> result(temperatures.size());
        for(int i=0;i<temperatures.size();i++){
            while(!stk.empty()&& stk.top().second<temperatures[i]){
                int prevDay=stk.top().first;
                stk.pop();
                result[prevDay]=i-prevDay;
            }
            stk.push({i, temperatures[i]});
        }
        return result;
    }
};
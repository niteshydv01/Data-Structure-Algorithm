class Solution {
public:
    int count = 0;
    string ans;

    void permute(vector<int>& element,
                 vector<bool>& used,
                 string& curr,
                 int k) {

        if(!ans.empty()) return;

        if(curr.size() == element.size()) {
            count++;

            if(count == k) {
                ans = curr;
            }
            return;
        }

        for(int i = 0; i < element.size(); i++) {

            if(!used[i]) {

                used[i] = true;

                curr += to_string(element[i]);

                permute(element, used, curr, k);

                curr.pop_back();

                used[i] = false;
            }
        }
    }

    string getPermutation(int n, int k) {

        vector<int> element;

        for(int i = 1; i <= n; i++) {
            element.push_back(i);
        }

        vector<bool> used(n, false);

        string curr = "";

        permute(element, used, curr, k);

        return ans;
    }
};
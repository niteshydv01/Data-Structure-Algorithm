class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for (int asteroid : asteroids) {
            bool current_survived = true;

            while (!s.empty() && s.top() > 0 && asteroid < 0) {
                if (s.top() < abs(asteroid)) {
                    s.pop();
                    continue;
                } 
                else if (s.top() > abs(asteroid)) {
                    current_survived = false;
                    break;
                }
                else {
                    s.pop();
                    current_survived = false;
                    break;
                }
            }

            if (current_survived) {
                s.push(asteroid);
            }
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
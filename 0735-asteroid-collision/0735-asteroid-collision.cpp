#include <vector>
#include <stack>
#include <numeric>
#include <algorithm>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> s;

        for (int asteroid : asteroids) {
            if (asteroid > 0 || s.empty() || s.top() < 0) {
                s.push(asteroid);
            } else {
                int current_abs_val = std::abs(asteroid);
                
                while (!s.empty() && s.top() > 0 && s.top() < current_abs_val) {
                    s.pop();
                }

                if (!s.empty() && s.top() > 0) {
                    if (s.top() == current_abs_val) {
                        s.pop();
                    }
                } else {
                    s.push(asteroid);
                }
            }
        }

        std::vector<int> result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};
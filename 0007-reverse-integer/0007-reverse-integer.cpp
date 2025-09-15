class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        bool e = false;

        if (x < 0) {
            e = true;
            if (x == INT_MIN) {
                return 0; // cannot flip INT_MIN safely
            }
            x = -x;
        }

        while (x > 0) {
            int t = x % 10;
            x = x / 10;

            // Overflow check: before multiplying ans by 10
            if (ans > (INT_MAX - t) / 10) {
                return 0; // Overflow would happen
            }

            ans = ans * 10 + t;
        }

        if (e) {
            return -ans;
        }
        return ans;
    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Count the sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert both to negatives for easier handling (avoid overflow with INT_MIN)
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long result = 0;

        // Subtract b * 2^x while it's <= a
        while (a >= b) {
            long long temp = b, multiple = 1;
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        return negative ? -result : result;
    }
};

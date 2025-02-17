class Solution {

public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0;
        int sign = 1;

        // Step 1: Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for optional sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert valid digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Step 4: Handle integer overflow
            if (sign * result < INT_MIN) return INT_MIN;
            if (sign * result > INT_MAX) return INT_MAX;
            
            i++;
        }

        return sign * result;
    }
};

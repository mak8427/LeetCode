class Solution {
public:
    int reverse(int x) {
        std::string num = std::to_string(x);
        std::string copy(num);
        bool negative = false;

        if (x < 0) {
            negative = true;
            copy.erase(0, 1); // Remove the negative sign
        }

        std::reverse(copy.begin(), copy.end());
        
        if (copy.size() == 1) {
            return std::stoi(copy) * (negative ? -1 : 1);
        }

        if (copy.at(0) == '0') {
            copy.erase(0, 1); // Remove leading zeros
        }

        if (copy.size() > 10) { // More than 10 digits means it overflows
            return 0;
        }

        long long reversed_num = std::stoll(copy);
        if (negative) {
            reversed_num = -reversed_num;
        }
        
        if (reversed_num < INT_MIN || reversed_num > INT_MAX) {
            return 0; // Check for 32-bit signed integer overflow
        }

        return static_cast<int>(reversed_num);
    }
};

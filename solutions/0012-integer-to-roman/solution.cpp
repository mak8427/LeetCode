class Solution {
public:
    string intToRoman(int num) {
        // Extract digits (ones digit at index 0, tens at index 1, etc.)
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        
        // We'll build the result by processing from the highest place digit
        string s = "";
        // Arrays to hold the symbols for each place:
        vector<string> ones  = {"I", "X", "C", "M"};
        vector<string> fives = {"V", "L", "D", ""};
        vector<string> tens  = {"X", "C", "M", ""};
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            int d = digits[i]; 
            int place = i;     
            
            if (d == 9) {
                s += ones[place] + tens[place];
            } else if (d >= 5) {
                s += fives[place];
                for (int j = 0; j < d - 5; j++) {
                    s += ones[place];
                }
            } else if (d == 4) {
                s += ones[place] + fives[place];
            } else { 
                for (int j = 0; j < d; j++) {
                    s += ones[place];
                }
            }
        }
        
        return s;
    }
};


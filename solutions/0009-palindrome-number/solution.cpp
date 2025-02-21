class Solution {
public:
     vector<int> get_digit_list(int n){
    vector<int> digits{};
    while (n > 0) {  // Stop only when n == 0
        digits.push_back(n % 10);
        n /= 10;
    
    }
        return digits;
    }
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        vector<int> digits = get_digit_list(x);
        vector<int> reversed_digits(digits);
        std::reverse(reversed_digits.begin(), reversed_digits.end());
        for(int i =0 ; i<reversed_digits.size() ; i++){
            //cout<<digits[i]<< "  "<<reversed_digits[i]<<"\n";
         if(digits[i] != reversed_digits[i]){
            return false;
         }   
        }




        return true;
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Base case

        unordered_map<char, string> m{
            {'2', "cba"}, {'3', "fed"}, {'4', "ihg"}, {'5', "lkj"},
            {'6', "onm"}, {'7', "srqp"}, {'8', "vut"}, {'9', "zyxw"}
        };

        vector<string> result;
        result.push_back(""); 

        for (char digit : digits) {
            vector<string> temp;
            string letters = m[digit];

            for (const string& combination : result) {
                for (char letter : letters) {
                    temp.push_back(combination + letter);
                }
            }
            result = temp;
        }

        return result;
    }
};


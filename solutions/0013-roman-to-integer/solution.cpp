class Solution {
public:
    int romanToInt(string s) {
        int n = 0;
        // Use char as key since s contains characters
        std::unordered_map<char, int> mymap{
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && mymap[s[i]] < mymap[s[i + 1]]) {
                n += mymap[s[i + 1]] - mymap[s[i]];
                i++; // Skip the next character since it's already processed
            } else {
                n += mymap[s[i]];
            }
        }
        
        return n;
    }
};


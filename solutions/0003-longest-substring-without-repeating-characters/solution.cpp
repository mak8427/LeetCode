class Solution {
public:
    int maxAt(vector<int>& vector_name) {
        int maxVal = INT_MIN;
        for (auto val : vector_name) {
            if (maxVal < val) maxVal = val;
        }
        return maxVal;
    }

    int lengthOfLongestSubstring(string s) {
        int len_s = s.length();
        if (len_s == 0) return 0;  // Handle empty string case

        int rep = 0;  // Track length of substring
        vector<int> reps;
        string sub = "";


        for (int i = 0; i < len_s; i++) {
            size_t pos = sub.find(s[i]);

            if (pos == string::npos) {
                // If character is NOT in sub, add it
                sub += s[i];
                rep++;
            } else {
                // If character is found, store length, remove previous occurrences
                reps.push_back(rep);
                sub = sub.substr(pos + 1) + s[i];  // Remove earlier part of the substring
                rep = sub.length();  // Update length accordingly
            }
        }

        // Push the last counted substring length
        reps.push_back(rep);


        return maxAt(reps);
    }
};



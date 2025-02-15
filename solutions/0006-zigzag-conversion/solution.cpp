class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) 
            return s; 

        vector<vector<char>> v(numRows); 

        int q = 0;                 
        bool switch_1 = true;       

        for (int i = 0; i < s.size(); i++) {
            v[q].push_back(s[i]);

            if (q == 0) {
                switch_1 = true;
            } else if (q == numRows - 1) {
                switch_1 = false;
            }

            if (switch_1) {
                q++;
            } else {
                q--;
            }
        }

        string result;
        for (auto& row : v) {
            for (char c : row) {
                result.push_back(c);
            }
        }
        return result;
    }
};


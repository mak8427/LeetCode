class Solution {
    private: 
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }            

public:
    string longestPalindrome(string s) {
        string sub = "";
        int starting_index = 0;
        int max_len = 0;
        if(s.size() == 1){return s;};
        if(s.size() == 2 && s[0] != s[1]){return s.substr(0, 1);};
        if(s.size() == 2 && s[0] == s[1]){return s;};


        for(int i=0 ; i<s.size();i++){
            for(int j=i+1; j<s.size();j++){
                if(check(s, i, j)){
                    if(j-i+1 > max_len){
                        max_len = j-i+1;
                        starting_index = i;
                    }
                }
            }
        }
        if(s.substr(starting_index, max_len) == "" && s.size()>0){return s.substr(0, 1);};
         return s.substr(starting_index, max_len);
    }
};

class Solution {
public:
    string LCP(string string1,string string2){
        string cum;
        for(int q=0; q<min(string1.size(),string2.size()); q++){
            if(string1[q] == string2[q]){
                cum+=string1[q];
            }
            else{ break;}
        }
        return cum;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string res =strs[0];
        for(int i=1; i<strs.size(); i++ ){
             res=LCP(res, strs[i]);
             
        }
        return res;
    }
};

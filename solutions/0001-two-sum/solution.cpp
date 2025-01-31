#include <iostream>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int len = nums.size();
    std::vector<int> solution;
    for (int i=0; i<len; i++ ){
        for (int l=0; l<len; l++ ){
            if (i!=l){
            int sum = nums[i]+nums[l];
            if(sum == target){
                solution.push_back(i);
                solution.push_back(l);
                return solution;

            }
            }
        }
        }
        return solution;

    }
    
};

class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = 1000000;
        for(int i=0; i<nums.size() -2 ; i++){
            int left = i + 1, right = nums.size() - 1;
            while(left <right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target){
                    return sum;
                }
                if (std::abs(sum - target) < std::abs(closest - target)) {
                    closest = sum;
                }

                if(sum <  target){
                    left++;
                }else{ right--;}
               
            }


        }
            return closest;

    }
};

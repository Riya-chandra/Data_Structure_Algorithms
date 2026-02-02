class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 3)
            return nums[0] + nums[1] + nums[2];

        int first = nums[0];
        int mn1 = INT_MAX, mn2 = INT_MAX;

        for(int i = 1; i < n; i++){
            if(nums[i] < mn1){
                mn2 = mn1;
                mn1 = nums[i];
            }
            else if(nums[i] < mn2){
                mn2 = nums[i];
            }
        }

        return first + mn1 + mn2;
    }
};

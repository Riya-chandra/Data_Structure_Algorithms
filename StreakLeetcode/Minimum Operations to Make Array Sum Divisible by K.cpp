class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
       for(auto num:nums){
        sum+=num;
       }
       int rem=sum%k; //and see ki kya diff aa rh h ..jitna diff hoga utna hi op krna hga 
       if(rem==0) return 0;
       return rem;
    }
};
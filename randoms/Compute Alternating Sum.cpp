class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n=nums.size();
        int add=0;
        // int sum=0;
        for(int i=0;i<n;i++){
            if(i%2==0) add+=nums[i];
            else{
                add-=nums[i];
            }
        }
        return add;
    }
};
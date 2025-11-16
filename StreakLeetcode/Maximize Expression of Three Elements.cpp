class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
      int n=nums.size();
      sort(nums.begin(),nums.end()) ;
        vector<int>result;
      //1 2 3 4 5
    
           result.push_back(nums[n-1]);
           result.push_back(nums[n-2]);
            result.push_back(nums[0]);
        return result[0]+result[1]-result[2];
    }
};
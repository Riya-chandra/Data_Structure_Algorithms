class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int n=nums.size();
        int reminder=0;//agr rem 0 hai tbhi 5 se divisible 
        for(int i=0;i<n;i++){
          reminder=(reminder*2+nums[i])%5;
          if(reminder==0)
          ans.push_back(true);
          else
            ans.push_back(false);
          
        }
        return ans;
    }
};
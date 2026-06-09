class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        int maxEl=INT_MIN;
        int minEl=INT_MAX;
        for(int &num :nums){
            maxEl=max(maxEl,num);
            minEl=min(minEl,num);
        }
      
        return 1L* k*(maxEl- minEl);
    }
};

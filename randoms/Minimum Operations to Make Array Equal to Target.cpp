class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        long long result=0;
        vector<int> diff(n);
         for(int i=0;i<n;i++){
            diff[i]=target[i]-nums[i];
         }
         int curr=0;
         int prev=0;
         for(int i=0;i<n;i++){
            curr=diff[i];

            //sign change
            if((curr>0 && prev<0)|| (curr<0 && prev>0)) {
             result+= abs(curr);
            }
            else if(abs(curr)>abs(prev)){
                result+=abs(curr-prev);
            }
            // else if(abs(curr)<=abs(prev)){
                //do nothing
            // }
            prev=curr;
         }
         return result;
    }
};
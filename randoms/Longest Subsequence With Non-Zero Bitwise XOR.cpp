class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorAll=0;
        int n=nums.size();
        for(int x:nums){
            xorAll^=x; //sb ka xor nikl liye 
        }
        if(xorAll!=0) return n;
        bool allZero=true;
        for(int x:nums){
            if(x!=0){
                allZero=false;
                break;
            }
        }
        if(allZero) return 0;
        return n-1;
    }
};
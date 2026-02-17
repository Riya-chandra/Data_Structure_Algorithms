class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        
        int n = nums.size();
        
        long long prevNotRob = 0;
        long long prevRob = nums[0];
        
        for(int i = 1; i < n; i++) {
            
            long long currNotRob = max(prevNotRob, prevRob);
            long long currRob = 0;
            
            if(colors[i] != colors[i-1]) {
                currRob = max(prevNotRob, prevRob) + nums[i];
            } 
            else {
                currRob = prevNotRob + nums[i];
            }
            
            prevNotRob = currNotRob;
            prevRob = currRob;
        }
        
        return max(prevNotRob, prevRob);
    }
};

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        // Calculate the total sum of the array
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        //the sum till now
        int currSum = 0;
        int res = 0;
        
        // Iterate through valid split points (leaving at least one element for the suffix)
        for(int i = 0; i < nums.size() - 1; i++) {
            currSum += nums[i]; // update prefix sum
            
            // Check if (PrefixSum - SuffixSum) is even
            // SuffixSum is calculated as (totalSum - currSum)
            if((currSum - (totalSum - currSum)) % 2 == 0) {
                res++;
            }
        }
        return res;
    }
};
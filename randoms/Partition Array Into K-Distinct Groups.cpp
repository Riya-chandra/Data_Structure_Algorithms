class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
           int n = nums.size();

        // if total elements can't be divided into groups of k
        if (n % k != 0) return false;

        int totalGroups=n/k;
        unordered_map<int, int> freq;
        for(int it:nums){
            freq[it]++;
        }
          for (auto& [num, count] : freq) {
            if (count > totalGroups) return false;
        }
        return true;
        
    }
};©leetcode
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        unordered_set<int> used;  
        int operations = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] != target[i]) {           
                if(used.find(nums[i]) == used.end()) {
                    operations++;                 
                    used.insert(nums[i]);
                }
            }
        }

        return operations;
    }
};

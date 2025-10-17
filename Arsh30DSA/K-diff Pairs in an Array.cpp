class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> result;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int diff = nums[i] - nums[j];
                if(abs(diff) == k) {
                    int a = min(nums[i], nums[j]);
                    int b = max(nums[i], nums[j]);
                    if(count(result.begin(), result.end(), make_pair(a,b)) == 0) {
                        result.push_back({a,b});
                    }
                }
            }
        }

        return result.size();
    }
};

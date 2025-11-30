class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return n; // need at least 0 greater -> all qualify

        sort(nums.begin(), nums.end());
        // threshold value is nums[n-k]
        int threshold = nums[n - k];
        // count elements strictly less than threshold
        int ans = lower_bound(nums.begin(), nums.end(), threshold) - nums.begin();
        return ans;
    }
};
©leetcode
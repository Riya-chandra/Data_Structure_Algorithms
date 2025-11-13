class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        // sort by absolute value descending
        sort(nums.begin(), nums.end(), [](int a, int b){
            return llabs((long long)a) > llabs((long long)b);
        });

        int k = (n + 1) / 2; // number of positive slots
        long long plus = 0, minus = 0;
        for (int i = 0; i < n; ++i) {
            long long sq = 1LL * nums[i] * nums[i];
            if (i < k) plus += sq;
            else minus += sq;
        }
        return plus - minus;
    }
};
©leetcode
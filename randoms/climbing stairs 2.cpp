class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
         vector<long long> dp(n + 1, 1e9); // large initial value
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int jump = 1; jump <= 3; jump++) {
                int prev = i - jump;
                if (prev >= 0) {
                    dp[i] = min(dp[i], dp[prev] + costs[i - 1] + jump * jump);
                }
            }
        }

        return dp[n];
    }
};
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);  // dp[i]: people who learn secret on day i
        vector<long long> share(n + 1, 0);  // share[i]: total people who can share on day i

        dp[1] = 1;
        long long totalSharing = 0;

        for (int day = 2; day <= n; ++day) {
            // Add new sharers who can start today
            if (day - delay >= 1)
                totalSharing = (totalSharing + dp[day - delay]) % MOD;

            // Remove people who forget today
            if (day - forget >= 1)
                totalSharing = (totalSharing - dp[day - forget] + MOD) % MOD;

            dp[day] = totalSharing;
        }

        // Final result: sum of people who still know secret on day n
        long long result = 0;
        for (int i = n - forget + 1; i <= n; ++i) {
            result = (result + dp[i]) % MOD;
        }

        return result;
    }
};

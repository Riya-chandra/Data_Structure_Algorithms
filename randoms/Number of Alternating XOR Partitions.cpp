class Solution {
public:
    static const int MOD = 1e9 + 7;

    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int n = nums.size();

        // Prefix XOR
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ nums[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = 1; 
        unordered_map<int, int> mp1, mp2;

        mp1[0] = 1;

        for (int i = 1; i <= n; i++) {
            int cur = prefix[i];
            
            if (mp1.count(cur ^ target1)) {
                dp[i][0] = (dp[i][0] + mp1[cur ^ target1]) % MOD;
            }
            if (mp2.count(cur ^ target2)) {
                dp[i][1] = (dp[i][1] + mp2[cur ^ target2]) % MOD;
            }

            mp1[cur] = (mp1[cur] + dp[i][1]) % MOD;
            mp2[cur] = (mp2[cur] + dp[i][0]) % MOD;
        }
        return (dp[n][0] + dp[n][1]) % MOD;
    }
};

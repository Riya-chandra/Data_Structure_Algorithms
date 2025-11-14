class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        if (n < 3) return 0;

        
        vector<long long> pref(n+1, 0);
        for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + capacity[i];

        long long ans = 0;
        
        unordered_map<long long, unordered_map<long long, long long>> mp;

        
        for (int r = 2; r < n; ++r) {
           
            int l = r - 2;
            mp[ capacity[l] ][ pref[l+1] ]++;

            long long need = pref[r] - (long long)capacity[r];
            if (mp.count(capacity[r]) && mp[ capacity[r] ].count(need)) {
                ans += mp[ capacity[r] ][ need ];
            }
        }

        return ans;
    }
};

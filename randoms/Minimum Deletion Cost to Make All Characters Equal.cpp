class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long totalCost = 0;
        vector<long long> freqCost(26, 0);

        for (int i = 0; i < s.size(); i++) {
            totalCost += cost[i];
            freqCost[s[i] - 'a'] += cost[i];
        }

        long long maxCharCost = 0;
        for (int i = 0; i < 26; i++) {
            maxCharCost = max(maxCharCost, freqCost[i]);
        }

        return totalCost - maxCharCost;
    }
};
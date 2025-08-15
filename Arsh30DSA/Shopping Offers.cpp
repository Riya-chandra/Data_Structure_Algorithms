class Solution {
public:
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int> needs, unordered_map<string,int>& memo) {
        // key for memoization
        string key = "";
        for (int x : needs) key += to_string(x) + ",";
        if (memo.count(key)) return memo[key];

        // base cost: buy without any offer
        int minCost = 0;
        for (int i = 0; i < needs.size(); i++) {
            minCost += needs[i] * price[i];
        }

        // try every special offer
        for (auto &offer : special) {
            vector<int> newNeeds(needs);
            bool canUse = true;
            for (int i = 0; i < needs.size(); i++) {
                if (newNeeds[i] < offer[i]) { // can't use this offer
                    canUse = false;
                    break;
                }
                newNeeds[i] -= offer[i];
            }
            if (canUse) {
                minCost = min(minCost, offer.back() + dfs(price, special, newNeeds, memo));
            }
        }

        return memo[key] = minCost;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string,int> memo;
        return dfs(price, special, needs, memo);
    }
};

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>> arr(n);

        for(int i = 0; i < n; i++) {
            arr[i] = {costs[i], capacity[i]};
        }

        sort(arr.begin(), arr.end());

        vector<int> prefixMax(n);
        prefixMax[0] = arr[0].second;
        for(int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], arr[i].second);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int cost1 = arr[i].first;
            int cap1 = arr[i].second;

            if(cost1 >= budget) break;

            ans = max(ans, cap1);

            int remaining = budget - cost1;
            int l = 0, r = i - 1, idx = -1;

            while(l <= r) {
                int mid = (l + r) / 2;
                if(arr[mid].first < remaining) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if(idx != -1) {
                ans = max(ans, cap1 + prefixMax[idx]);
            }
        }

        return ans;
    }
};

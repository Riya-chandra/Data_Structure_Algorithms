class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());

        long long ans = 0;
        int n = happiness.size();
        for (int i = 0; i < k; i++) {
            int curr = happiness[n - 1 - i] - i;
            if (curr > 0)
                ans += curr;
            else
                break; 
        }

        return ans;
    }
};

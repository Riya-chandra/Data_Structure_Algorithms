class Solution {
public:
    int countCompromisedSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int currOR = 0;
            int mx = 0;

            for (int j = i; j < n; j++) {
                currOR |= arr[j];
                mx = max(mx, arr[j]);

                if (currOR == mx) {
                    count++;
                }
            }
        }
        return count;
    }
};

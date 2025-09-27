class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        long long result = 0;
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = target[i];
        }
        int curr = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            curr = diff[i];
            if (abs(curr) > abs(prev)) {
                result += abs(curr - prev);
            }
            prev = curr;
        }
        return result;
    }
};
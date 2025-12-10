class Solution {
public:
  static const int MOD = 1e9 + 7;

    long long fact(int k) {
        long long res = 1;
        for (int i = 1; i <= k; i++) {
            res = (res * i) % MOD;
        }
        return res;
    }

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int mn = complexity[0];
        for (int i = 1; i < n; i++) {
            // strtaing point is the 0th index hence it shoudl be very impt to
            // have the greater number at 1 index
            if (complexity[i] <= mn) {
                return 0;
            }
            mn = min(mn, complexity[i]);
        }
       return (int)fact(n - 1);
    }
};
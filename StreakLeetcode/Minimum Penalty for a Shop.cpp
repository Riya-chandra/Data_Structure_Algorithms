#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<int> prefixN(n + 1, 0);
        vector<int> suffixY(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefixN[i] = prefixN[i - 1];
            if (s[i - 1] == 'N') prefixN[i]++;
        }

        for (int i = n - 1; i >= 0; i--) {
            suffixY[i] = suffixY[i + 1];
            if (s[i] == 'Y') suffixY[i]++;
        }

        int best = INT_MAX, ans = 0;
        for (int j = 0; j <= n; j++) {
            int pen = prefixN[j] + suffixY[j];
            if (pen < best) {
                best = pen;
                ans = j;
            }
        }
        return ans;
    }
};
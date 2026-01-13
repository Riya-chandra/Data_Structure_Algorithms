// s1 = "abcde"
// s2 = "ace"
// Output = 3   // "ace"

#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m]; //last cell apne aap bhr jyega answer se the longest common seq
}

int main() {
    string s1 = "abcde", s2 = "ace";
    cout << lcs(s1, s2);
    return 0;
}

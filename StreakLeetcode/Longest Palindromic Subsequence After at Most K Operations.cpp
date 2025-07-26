#include <string>
#include <vector>
using namespace std;
class Solution {
public:
     int dp(int i, int j, int rem, const string &s, vector<vector<vector<int>>> &memoRef) {
        if (i > j) return 0;
        if (i == j) return 1; // Single character is always a palindrome

        if (memoRef[i][j][rem] != -1) return memoRef[i][j][rem];

        // Case 1: Skip one character from either side
        int ans = max(dp(i+1, j, rem, s, memoRef), dp(i, j-1, rem, s, memoRef));

        // Case 2: Modify a character to match
        int diff = abs(s[i] - s[j]); 
        int cost = min(diff, 26 - diff);  // Wrapping around 'z' to 'a'

        if (cost <= rem) {
            ans = max(ans, 2 + dp(i+1, j-1, rem - cost, s, memoRef));
        }

        return memoRef[i][j][rem] = ans;
    }

    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
        return dp(0, n-1, k, s, memo);
    }
};
class Solution {
public:
    int almostPalindromic(string s) {
        int ans = 0;
        int n = s.size();

       
        for(int i = 0; i < n; i++){
            for(int j = ans+i; j < n; j++){ 
                if(check(s, i, j)){
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return (ans == 0 ? -1 : ans);
    }


    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool check(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return isPalindrome(s, l + 1, r) ||
                       isPalindrome(s, l, r - 1);
            }
        }
        return true;
    }
};

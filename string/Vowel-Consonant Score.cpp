class Solution {
public:
    int vowelConsonantScore(string s) {
        int countV = 0;
        int countC = 0;

        for (char c : s) {
            if (c >= 'a' && c <= 'z') { 
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    countV++;
                } else {
                    countC++;
                }
            }
        }

        if (countC == 0) return 0;

        return countV / countC;
    }
};

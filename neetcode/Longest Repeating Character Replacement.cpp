class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int l = 0, maxCount = 0, result = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxCount = max(maxCount, count[s[r]]);

            while ((r - l + 1) - maxCount > k) {
                count[s[l]]--;
                l++;  //aage pad gy window shrink 
            }

            result = max(result, r - l + 1);
        }

        return result;
    }
};

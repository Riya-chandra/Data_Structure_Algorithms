class Solution {
public:
    // Build Longest Prefix Suffix (LPS) array
    vector<int> buildLPS(string& pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0, i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {  //age piche ka
                lps[i++] = ++len; ////lps array m i position ka value 1 se increase kr do 
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i++] = 0; ////not equal then not increaing length only i increase
                }
            }
        }
        return lps;
    }

    // KMP search
    bool kmpSearch(string& text, string& pat) {
        vector<int> lps = buildLPS(pat);
        int i = 0, j = 0, n = text.size(), m = pat.size();

        while (i < n) {
            if (text[i] == pat[j]) {
                i++; j++;
                if (j == m) return true; // found
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string s = a;
        int count = 1;

        // keep appending until s is >= b
        while (s.size() < b.size()) {
            s += a;
            count++;
        }

        // check current string
        if (kmpSearch(s, b)) return count;

        // check one more append (to cover boundary overlap)
        s += a;
        if (kmpSearch(s, b)) return count + 1;

        return -1;
    }
};

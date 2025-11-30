class Solution {
public:
    int maxDistinct(string s) {
        string stri=s;
        unordered_set<char>st;
        for(char c:stri){
            st.insert(c);
        }
        return st.size();
    }
};©leetcode
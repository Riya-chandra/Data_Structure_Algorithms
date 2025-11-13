class Solution {
public:
    long long removeZeros(long long n) {
        string s=to_string(n); //"1020030"
        int size=s.length();
        vector<char> result;
        for(int i=0;i<size;i++){
            if(s[i]!='0') {
                result.push_back(s[i]);
            }
        }
         // convert result vector<char> to string
        string num = "";
        for (char c : result) {
            num += c;
        }

        return stoll(num);  
    }
};©leetcode
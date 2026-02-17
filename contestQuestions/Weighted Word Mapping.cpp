class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string ans = "";
        
        for(string &word : words) {
            
            int sum = 0;
        
            for(char ch : word) {
                sum += weights[ch - 'a'];
            }
            
            int modulo = sum % 26;
            char mapped = 'z' - modulo;
            
            ans.push_back(mapped);
        }
        
        return ans;
    }
};

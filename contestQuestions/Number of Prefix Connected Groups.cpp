class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
      
        
        unordered_map<string, int> mp;
        
       
        for(string &word : words) {
            
            if(word.size() < k) continue;
            
            string prefix = word.substr(0, k);
            mp[prefix]++;
        }
        
        int groups = 0;
        
        for(auto &it : mp) {
            if(it.second >= 2) {
                groups++;
            }
        }
        
        return groups;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> freq;
        for(int x : nums) freq[x]++;

        for(auto it : freq) {
            v.push_back({it.first, it.second});  

        }

        sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second;  
        });

        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};

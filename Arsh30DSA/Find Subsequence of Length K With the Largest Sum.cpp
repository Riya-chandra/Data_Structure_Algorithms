class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<pair<int, int>> valIndex;
        for (int i = 0; i < n; ++i) {
            valIndex.push_back({nums[i], i});
        }

      
        sort(valIndex.begin(), valIndex.end(), [](auto &a, auto &b) {
            return a.first > b.first; //value k basis p sorting kr do   ...because valid index have two thing ..that i value as well as index
        });

     
        vector<pair<int, int>> topK(valIndex.begin(), valIndex.begin() + k);

      
        sort(topK.begin(), topK.end(), [](auto &a, auto &b) {
            return a.second < b.second;  //chote se bare m sort kr di and jo bara value h usko extract kro  according to the index k basis p 
        });

        // Step 5: Extract values only for the result
        vector<int> result;
        for (auto &p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};
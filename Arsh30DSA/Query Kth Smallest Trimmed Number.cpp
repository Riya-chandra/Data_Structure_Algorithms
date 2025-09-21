class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                       vector<vector<int>>& queries) {
        // we have to trim the queries[i][1] and take the queries[i][0] small
        // ele for the output int m=nums[0].size(); //3

        // vector<int> result;
        // for(int i=m;i>=0;i--){
        //      int trimDigit=nums[i]/10^m;
        //      result.push_back(trimDigit);
        // }
        // sort(result.begin(),result.end());
        // return queries[]
        vector<int> result;
        for (auto& q : queries) {
            int k = q[0];
            int trimLen = q[1];

            vector<pair<string, int>> trimmed;
            for (int i = 0; i < nums.size(); i++) {
                string s = nums[i].substr(
                    nums[i].size() -
                    trimLen); // s= num[2].substr(3-1) ,s=251.substr(2)= from 2
                              // to end tk ka sub =1 : s=1
                trimmed.push_back({s, i}); // 1 push and index 2
            }
            sort(trimmed.begin(), trimmed.end(), [](auto& a, auto& b) {
                if (a.first == b.first)
                    return a.second < b.second;
                return a.first < b.first;
            });
            result.push_back(trimmed[k - 1].second);
        }
        return result;
    }
};
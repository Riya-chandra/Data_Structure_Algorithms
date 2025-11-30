#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
    
        unordered_map<int,int> lastRev; 
        int ans = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (lastRev.count(nums[i])) {
                ans = min(ans, i - lastRev[nums[i]]);
            }

            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            int rev = stoi(s); 
            lastRev[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

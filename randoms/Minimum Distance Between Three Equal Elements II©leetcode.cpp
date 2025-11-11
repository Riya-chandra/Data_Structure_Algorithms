
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp; // har number ke indices store
        int ans = INT_MAX;

        // step 1: har value ke indices store kar lo
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        // step 2: har value ke liye dekho kya 3 ya usse zyada baar aayi hai
        for (auto &x : mp) {
            vector<int> v = x.second;
            if (v.size() >= 3) {
                // step 3: har 3 consecutive indices ke liye span nikal lo
                for (int i = 0; i + 2 < v.size(); i++) {
                    int span = v[i+2] - v[i];
                    ans = min(ans, 2 * span);
                }
            }
        }

        // step 4: agar koi triple hi nahi mila toh -1
        return (ans == INT_MAX) ? -1 : ans;
    }
};
©leetcode
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int ageA = ages[i];
            if(ageA < 15) continue; // 15 se neeche request possible nahi

            // Find left bound: first age > 0.5*ageA + 7
            int minAge = ageA / 2 + 7;
            int left = upper_bound(ages.begin(), ages.end(), minAge) - ages.begin();

            // Find right bound: last age ≤ ageA
            int right = upper_bound(ages.begin(), ages.end(), ageA) - ages.begin() - 1;

            if(right >= left) {
                ans += right - left; // minus 1 for self automatically
            }
        }

        return ans;
    }
};

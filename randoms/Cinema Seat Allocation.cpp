#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // defining groups (we only use grp4, grp2, grp5 effectively)
        vector<int> grp1 = {2, 3, 4, 5};
        vector<int> grp2 = {4, 5, 6, 7};
        vector<int> grp3 = {6, 7, 8, 9};

        // Step 1: Store reserved seats row-wise
        unordered_map<int, unordered_set<int>> reserved;
        for (auto &seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]); // seat[0]=row, seat[1]=col
        }

        int ans = 0;

        // Step 2: Iterate through each row that has reservations
        for (auto &r : reserved) {
            int row = r.first;
            unordered_set<int> blocked = r.second;

            // check 3 possible 4-seat groups
            bool leftFree = true;
            bool midFree = true;
            bool rightFree = true;

            // check left group [2,3,4,5]
            for (int s : grp1) {
                if (blocked.count(s)) {
                    leftFree = false;
                    break;
                }
            }

            // check middle group [4,5,6,7]
            for (int s : grp2) {
                if (blocked.count(s)) {
                    midFree = false;
                    break;
                }
            }

            // check right group [6,7,8,9]
            for (int s : grp3) {
                if (blocked.count(s)) {
                    rightFree = false;
                    break;
                }
            }

            int add = 0;
            if (leftFree) add++;
            if (rightFree) add++;
            if (!leftFree && !rightFree && midFree) add++;
            ans += add;
        }

       //jo v unordered set m nhi aaya usme wo 2 grp ko host kr skta hai 
        ans += 2 * (n - reserved.size());

        return ans;
    }
};
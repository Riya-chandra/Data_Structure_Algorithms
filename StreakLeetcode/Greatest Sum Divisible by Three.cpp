#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0;
        vector<int> rem1, rem2;

        for (int num : nums) {
            total += num;
            if (num % 3 == 1) rem1.push_back(num);
            else if (num % 3 == 2) rem2.push_back(num);
        }

        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        // Case 1: Perfectly divisible
        if (total % 3 == 0) return total;

        // Case 2: remainder = 1
        if (total % 3 == 1) {
            int option1 = INT_MIN, option2 = INT_MIN;

            if (rem1.size() >= 1)
                option1 = total - rem1[0];

            if (rem2.size() >= 2)
                option2 = total - rem2[0] - rem2[1];

            return max(option1, option2);
        }

        // Case 3: remainder = 2
        else {
            int option1 = INT_MIN, option2 = INT_MIN;

            if (rem2.size() >= 1)
                option1 = total - rem2[0];

            if (rem1.size() >= 2)
                option2 = total - rem1[0] - rem1[1];

            return max(option1, option2);
        }
    }
};

#include <vector>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int i = 1;

        while (i < n - 1) {
            // Skip duplicates to the left and right
            int prev = i - 1;
            while (prev >= 0 && nums[prev] == nums[i]) prev--;

            int next = i + 1;
            while (next < n && nums[next] == nums[i]) next++;

            // If valid non-equal neighbors exist
            if (prev >= 0 && next < n) {
                if (nums[i] > nums[prev] && nums[i] > nums[next]) {
                    count++; // Hill
                }
                else if (nums[i] < nums[prev] && nums[i] < nums[next]) {
                    count++; // Valley
                }
            }

            // Move to next new number (skip all duplicates)
            i = next;
        }

        return count;
    }
};

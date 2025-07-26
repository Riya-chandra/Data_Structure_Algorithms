#include <vector>
using namespace std;


class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int firstP = lower_bound(begin(nums), end(nums), 1) - begin(nums);
        int firstN = lower_bound(begin(nums), end(nums), 0) - begin(nums);

        return max(n-firstP, firstN);
        
    }
};
#include <vector>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int k = 3;
        int flips = 0;
        vector<bool> isFlipped(n, false);
        int flipCountFromPastForCurri = 0;

        for (int i = 0; i < n; i++)
        {
            if (i >= k && isFlipped[i - k] == true)
            {
                flipCountFromPastForCurri--;
            }

            if (flipCountFromPastForCurri % 2 == nums[i])
            {
                if (i + k > n)
                {
                    return -1;
                }
                flipCountFromPastForCurri++;
                isFlipped[i] = true;
                flips++;
            }
        }

        return flips;
    }
};
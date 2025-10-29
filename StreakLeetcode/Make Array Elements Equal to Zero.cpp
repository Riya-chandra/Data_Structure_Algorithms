class Solution {
public:
    // helper function to simulate process
    bool simulate(vector<int> nums, int curr, int direction) {
        int n = nums.size();

        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) {
                curr += direction;
            } else {
                nums[curr]--;
                direction *= -1; // reverse direction
                curr += direction;
            }
        }

        // check if all become zero
        for (int x : nums)
            if (x != 0) return false;
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (simulate(nums, i, -1))
                    count++;
                if (simulate(nums, i, 1))
                    count++;
            }
        }
        return count;
    }
};

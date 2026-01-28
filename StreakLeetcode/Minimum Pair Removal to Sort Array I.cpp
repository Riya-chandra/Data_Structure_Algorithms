class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        // jab tak array non-decreasing na ho
        while (true) {

            // sorted hai ya nahi
            bool sorted = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted)
                break;

            int minSum = INT_MAX;
            int idx = 0;

            for (int i = 0; i < nums.size() - 1; i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            vector<int> ans;
            for (int i = 0; i < idx; i++)
                ans.push_back(nums[i]);
            ans.push_back(minSum);
            for (int i = idx + 2; i < nums.size(); i++)
                ans.push_back(nums[i]);

            nums = ans;
            count++;
        }

        return count;
    }
};

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        while (true) {
            int i = 0, j = n - 1;
            int found = 0;

            while (i <= j) {
                int mid = (i + j) / 2;

                if (nums[mid] == original) {
                    original *= 2;   
                    found = 1;       
                    break;           
                }
                else if (nums[mid] < original) {
                    i = mid + 1;
                } 
                else {
                    j = mid - 1;
                }
            }

            if (!found) break;   
        }

        return original;
    }
};
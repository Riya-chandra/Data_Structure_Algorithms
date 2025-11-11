class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        int ops = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > nums[i]) {
                st.pop();
            }
            if (nums[i] == 0)
                continue;
        
        if (st.empty() || st.top() < nums[i]) {
            st.push(nums[i]);
            ops++;
        }
        }
        return ops;
    }
};
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        int longest = 0;
        int i = 1; // start from index 1, because we check arr[i-1] and arr[i+1]

        while (i < n - 1) {
            // check if current is a peak
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int left = i - 1;
                int right = i + 1;

                // go left while strictly increasing
                while (left > 0 && arr[left - 1] < arr[left]) left--;

                // go right while strictly decreasing
                while (right < n - 1 && arr[right] > arr[right + 1]) right++;

                int currLen = right - left + 1;
                longest = max(longest, currLen);

                // Move i to end of this mountain
                i = right;
            } else {
                i++;
            }
        }
        return longest;
    }
};

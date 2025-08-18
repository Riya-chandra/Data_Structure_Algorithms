class Solution {
public:
    bool canMake(const vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;

        for (int b : bloomDay) {
            if (b <= day) {
                flowers++;
                if (flowers == k) {      // k consecutive phool mil gaye
                    bouquets++;
                    flowers = 0;         // next bouquet ke liye reset
                    if (bouquets >= m)   // early exit optimization
                        return true;
                }
            } else {
                flowers = 0;             // streak toot gayi
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need = 1LL * m * k;
        if (need > (long long)bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canMake(bloomDay, m, k, mid)) {
                high = mid;      // possible hai, aur kam din try karo
            } else {
                low = mid + 1;   // possible nahi, zyada din chahiye
            }
        }
        return low;            
    }
};

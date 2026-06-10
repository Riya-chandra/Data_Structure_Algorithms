class Solution {
public:

    int longest(vector<int>& bars) {
        sort(bars.begin(), bars.end());

        int mx = 1;   // max consecutive length
        int cnt = 1;  // current consecutive length

        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1)
                cnt++;
            else
                cnt = 1;

            mx = max(mx, cnt);
        }

        return mx;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        // horizontal side length
        int h = longest(hBars) + 1;

        // vertical side length
        int v = longest(vBars) + 1;

        // largest possible square side
        int side = min(h, v);

        return side * side;
    }
};

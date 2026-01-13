class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        // thik hai agr 1,1 hua same coordinate of x and y then no need to cal
        // diff of teh x and y coordinate of the same ith index
        int n = points.size();
        int count = 0;
        // int start = points[0]; // first index is the starting point
        for (int i = 0; i < n - 1; i++) {
            // starting index
            int x = abs(points[i + 1][0] - points[i][0]);
            int y = abs(points[i + 1][1] - points[i][1]);

        count += max(x, y);

        }
        return count;
    }
};

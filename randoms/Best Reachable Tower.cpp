class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int n = towers.size();
        int bestQ = -1;
        vector<int> ans = {-1, -1};

        for(int i = 0; i < n; i++) {
            int x = towers[i][0];
            int y = towers[i][1];
            int q = towers[i][2];

            int dist = abs(x - center[0]) + abs(y - center[1]);

            if(dist <= radius) {   
                if(q > bestQ) {
                    bestQ = q;
                    ans = {x, y};
                } 
                else if(q == bestQ) {
                    if(x < ans[0] || (x == ans[0] && y < ans[1])) {
                        ans = {x, y};
                    }
                }
            }
        }

        return ans;
    }
};

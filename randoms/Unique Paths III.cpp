class Solution {
public:
    int n;
    int m;
    int dfs(vector<vector<int>>& grid, int i, int j, int remain) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1)
            return 0;
        if (grid[i][j] == 2)
            return (remain == 0) ? 1 : 0;

        int temp = grid[i][j];
        grid[i][j] = -1;
        remain--;

        int paths = dfs(grid, i + 1, j, remain) + dfs(grid, i - 1, j, remain) +
                    dfs(grid, i, j + 1, remain) + dfs(grid, i, j - 1, remain);

        grid[i][j] = temp;
        remain++;
        return paths;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int start_i;
        int start_j;
        int countOfZeros = 0; // counting of zeroes and at the end we have to check the
               // conidtion whather the count beacome zero or not
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n;j++) {
                if (grid[i][j] == 0)
                    countOfZeros++;
                else if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                } // locating and strting from teh 1 we are going
            }
        }
        return dfs(grid, start_i, start_j, countOfZeros + 1); //because intially it only cout zero but baad m ye visited ele ko v count kr rh dfs functin m and also
        //plus 1 isiliye due to the 1st startingindex which is already visited 
    }
};
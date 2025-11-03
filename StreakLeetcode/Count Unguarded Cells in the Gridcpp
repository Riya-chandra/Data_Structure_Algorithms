class Solution {
public:
    void markDirections(int m, int n, vector<vector<int>>& grid, int x, int y) {
        // Up
        for (int i = x - 1; i >= 0; i--) {
            if (grid[i][y] == 1 || grid[i][y] == 2) break;
            grid[i][y] = 3;
        }
        // Down
        for (int i = x + 1; i < m; i++) {
            if (grid[i][y] == 1 || grid[i][y] == 2) break;
            grid[i][y] = 3;
        }
        // Left
        for (int j = y - 1; j >= 0; j--) {
            if (grid[x][j] == 1 || grid[x][j] == 2) break;
            grid[x][j] = 3;
        }
        // Right
        for (int j = y + 1; j < n; j++) {
            if (grid[x][j] == 1 || grid[x][j] == 2) break;
            grid[x][j] = 3;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // 1 for walls
        for (auto &w : walls) {
            grid[w[0]][w[1]] = 1;
        }
        // 2 for guards
        for (auto &g : guards) {
            grid[g[0]][g[1]] = 2;
        }

        // Mark guarded cells
        for (auto &g : guards) {
            markDirections(m, n, grid, g[0], g[1]);
        }

        // Count unguarded
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) count++;
            }
        }

        return count;
    }
};

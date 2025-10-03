class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'X') {
                    // Agar ye same ship ka continuation hai, skip
                    if(i > 0 && board[i-1][j] == 'X') continue;
                    if(j > 0 && board[i][j-1] == 'X') continue;

                    // Otherwise ek new ship start
                    count++;
                }
            }
        }
        return count;
    }
};



class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        // Direction vectors: up, down, left, right
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        board[i][j] = '.'; // mark visited

        for(auto &d : dirs) {
            int ni = i + d.first;
            int nj = j + d.second;

            if(ni >= 0 && nj >= 0 && ni < m && nj < n && board[ni][nj] == 'X') {
                dfs(board, ni, nj, m, n);
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'X') {
                    count++;
                    dfs(board, i, j, m, n);
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    int n, m;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void dfs(vector<vector<int>>& grid, vector<vector<int>>& time, int i, int j, int t) {
    if(i<0 || i>=n || j<0 ||j>=m ) return ;
    if(grid[i][j]==0) return ;
    if(time[i][j]<=t) return ;
    time[i][j]=t;

    for(int k=0;k<4;k++){
        int ni=i+dirs[k][0];
        int nj=j+dirs[k][1];
        dfs(grid,time,ni,nj,t+1);
    }

}
    int orangesRotting(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) {
                    dfs(grid,time,i,j,0);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(time[i][j]==INT_MAX) return -1;
                    ans=max(ans,time[i][j]);
                }
            }
        }
        return ans;
    }
};
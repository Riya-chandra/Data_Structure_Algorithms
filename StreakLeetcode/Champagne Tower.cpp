#include <algorithm>
#include <cmath>
class Solution {
public:
double dp[101][101];
double solve(int poured,int i,int j){
    if(i<0 || j<0 || i<j) return 0;
    if(i==0&&j==0) return poured;
    if(dp[i][j]!=-1) return dp[i][j];
    double upleft=(solve(poured,i-1,j-1)-1)/2.0;
    double upright=(solve(poured,i-1,j)-1)/2.0;
    if(upleft<0){
        upleft=0.0;
    }
    if(upright<0){
        upright=0.0;
    }
    return dp[i][j]=upleft+upright;

}
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j]=-1;
            }
        }
        return std::min(1.0,solve(poured,query_row,query_glass));
    }
};
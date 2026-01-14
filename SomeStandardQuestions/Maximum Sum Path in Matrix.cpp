// Matrix:
// 10 10  2  0
// 1   0  0 30
// 0  10  4  0

// Output: 50

#include <bits/stdc++.h>
using namespace std;

int maxPathSum(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> dp=mat;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up=dp[i-1][j];
            int leftdia=(j>0) ? dp[i-1][j-1]:0;
            int rightdia=(j<m-1) ? dp[i-1][j+1]:0;
            d[i][j] +=max(up,leftdia,rightdia);//current cell
        }
    }
    return *max_element(dp[n-1].begin(),dp[n-1].end());
}

int main() {
    vector<vector<int>> mat = {
        {10, 10, 2, 0},
        {1, 0, 0, 30},
        {0, 10, 4, 0}
    };

    cout << maxPathSum(mat);
    return 0;
}
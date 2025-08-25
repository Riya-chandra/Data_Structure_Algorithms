class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty()) return {};
        int m =mat.size();
        int n=mat[0].size();
        //dia=for in=[0][0] up=[][1](out of bound) down=[1][0] up=[0][1] down=[0][2] up=[1][1]
        vector<int> result;
        result.reserve(m * n);
        for(int d=0;d<m+n-1;d++){
            vector<int> temp;
            int r=(d<n) ?0 :d-n+1;
            int c=(d<n) ?d:n-1;
            while(r<m && c>=0){
                temp.push_back(mat[r][c]);
                r++;
                c--;
            }
            if(d%2==0){
                reverse(temp.begin(),temp.end());
            }
result.insert(result.end(),temp.begin(),temp.end());
        }
return result;
    }
};
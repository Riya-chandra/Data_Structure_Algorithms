class Solution {
public:

    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n =matrix.size();
        // vector<vector<long long>negVisit(n,vector<long long>(m));
        int countNeg=0;
        long long sum=0;
        int smallestAmongAllOddNeg=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               sum+=abs(matrix[i][j]);
               if(matrix[i][j]<0) countNeg++; //mtlb agr positve hai toh sum m add krte chlo
               smallestAmongAllOddNeg=min(smallestAmongAllOddNeg,abs(matrix[i][j]));
            //thik hai toh huko count lene k baad jo count m sbse chota digit hoga agr even hua toh kuch nhi sb ka additon le lo kyuki sb pos ho jyga ut agr odd hua toh sbse chtpe wale ko chor do
            }
        }
        if(countNeg%2 ==0 ){
            //mtlb even hai toh sb ka sum return kr do 
            return sum;
        }
return sum-2*smallestAmongAllOddNeg;
    }
};






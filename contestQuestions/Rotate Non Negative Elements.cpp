class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n=nums.size();
        // vector<int>nonNeg; //vector n le kr ek unordered set ya map le lete hai jisse unke pass unka index v stored rhega
        vector<pair<int,int>> nonNeg;
        
        for(int i=0;i<n;i++){
            if(nums[i]>=0) {
                nonNeg.push_back({nums[i],i});
            }//we get the arr of non neg characters = [5,4,6]
            //now apply the rotation on them by k 
            //wahi position repeat honge after the mth time ....like agr size 4 hai toh after 4 repaet hone lgege

        }
           int m = nonNeg.size();
        if(m == 0) return nums;
          k %= m;

        // rotated values
        vector<int> rotated(m);
        for(int i = 0; i < m; i++){
            rotated[i] = nonNeg[(i + k) % m].first;
        }

        // put back
        for(int i = 0; i < m; i++){
            nums[nonNeg[i].second] = rotated[i];
        }

        return nums;
    }
};

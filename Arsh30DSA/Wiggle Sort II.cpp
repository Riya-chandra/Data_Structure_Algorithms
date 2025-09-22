class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted=nums;  //changes will reflect in original array
        sort(sorted.begin(),sorted.end());
        int mid=(n+1)/2;
        int i=mid-1;  //chote m sbse bara 
        int j=n-1; //sbse bara at right  
        // we have to make sure ki agr even h toh n jo v sbse bara j place krege toh uske imm baad place kr skte h
        //and when odd then mak esure
        for(int k=0;k<n;k++){
            if(k%2==0) {
               nums[k] = sorted[i--];
            }
            else{
                nums[k]=sorted[j--];
            }
        }
    }
};
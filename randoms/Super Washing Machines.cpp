class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n=machines.size();
        int sum=0;
        for(auto it:machines){
            sum+=it;
        }
        if(sum%n!=0) return -1;
         int target=sum/n;
         int balance=0;
         int ans=0;
         for(int i=0;i<n;i++){
            int diff=machines[i]-target;
            balance+=diff;
         
           ans = max(ans, max(abs(balance), diff));
         }
         return ans;
    }
};
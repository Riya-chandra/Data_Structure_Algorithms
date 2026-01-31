class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
      vector<int> box(50, 0);

        for(int i=lowLimit;i<=highLimit;i++){
           int x=i;
           int sum=0;
           while(x>0){
            sum+=x%10;
            x/=10;
           }
           box[sum]++;
        }
        int ans=0;
        for(int cnt:box){
            ans=max(ans,cnt);
        }
        return ans;
    }
};

class Solution {
public:
const int M=1e9+7;
int N;
int t[101][101][101];
int solve(int i,int gain,int people, int minProfit, vector<int>& group, vector<int>& profit){
if(people>N){
return 0;
}

if(i==group.size()){
    if(gain>=minProfit){
        return t[i][gain][people]=1;
    } return t[i][gain][people]=0;
}
if(t[i][gain][people]!=-1){
    return t[i][gain][people];
}
long long notTaken=solve(i+1,gain,people,minProfit,group,profit)%M;
long long taken=solve(i+1,min(gain+profit[i],minProfit),people+group[i],minProfit,group,profit)%M;
return t[i][gain][people]= (notTaken%M+taken%M)%M;
}
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N=n;
        memset(t,-1,sizeof(t));
         return solve(0,0,0,minProfit,group,profit );
    }
};

class Solution {
public:
vector<vector<int>> Finalresult;
void backtrack(int k,int n, int start, vector<int> &ans){
    if(ans.size()==k && n==0){
        Finalresult.push_back(ans);
    }
    if(ans.size()>k || n<0) return ;
    for(int i=start;i<=9;i++){
        ans.push_back(i);
        backtrack(k,n-i,i+1,ans);
        ans.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;//for making a array
       
        if(n<k) return {}; //agr k=4 and n=1 then sum could never be 1 by 4 digits from 1-9
        backtrack(k,n,1,ans);
        return Finalresult;

    }
};
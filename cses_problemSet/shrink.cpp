#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int> ans(n);
    for(int i=0;i<n;i++)
        ans[i]=i+1;
     swap(ans[1],ans[n-1]);
    for(auto &X : ans) cout << X << " ";

     cout<<"\n";
    
    }
    return 0;
}
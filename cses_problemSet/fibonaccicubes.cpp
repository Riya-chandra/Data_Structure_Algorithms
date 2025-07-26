#include <iostream>
#include <algorithm>
using namespace std;
 int fib[12];
void solve(){
    int n;
    int m;
    cin >> n >> m;
for(int i = 0; i < m; i++){
   int dim[3];
   for(int j=0;j<3;j++){
   cin>>dim[j];
   }
   sort(dim,dim+3);
   cout<<(dim[0]>= fib[n] && dim[2]>=fib[n+1]);
}
    cout<<endl;
}

 int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
 }
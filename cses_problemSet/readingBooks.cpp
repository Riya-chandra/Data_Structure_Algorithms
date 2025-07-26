#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<long long> t(n);
  long long sum=0;
  long long max_t=0;
  for(int i =0;i<n;i++){
    cin>>t[i];
    sum+=t[i];
    max_t=max(max_t,t[i]);
  }
  cout << max(2 * max_t, sum) << "\n";

    return 0;
}
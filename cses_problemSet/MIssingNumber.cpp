#include<bits/stdc++.h>
using namespace std;

int main(){
   long long n;
   cin>>n;
   long long sum=(n*(n+1))/2;
   long long result=0;
 
for(int i=0;i<n-1;i++){
     long long num;
     cin>>num;
     result+=num;
    }
   cout<<(sum-result)<<endl;
}
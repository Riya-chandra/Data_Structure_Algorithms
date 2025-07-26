#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans=0;
    int count=0;
    char ch = 'A';
   for(char d:s){
     if(d==ch){
        count++;
        ans=max(ans,count);
     }
     else{
        ch=d;
        count=1;
     }
    
   }
   cout<<ans<<endl;
}
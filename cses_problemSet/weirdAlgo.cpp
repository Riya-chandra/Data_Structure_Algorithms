#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    cout<<n<<endl;
    while(n>1){
        if(n%2==0)
            n/=2; 
        else
            n=3*n+1;
        cout<<n<<endl;
    }
    return 0;
}

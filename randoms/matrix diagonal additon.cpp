#include<bits/stdc++.h>
using namespace std;

void diagonal()
int main(){
    int n; //n cross n matrix 
    cin>>n;
    vector<vector<int,int>> grid(n ,vector<int>(n));
    //meaning it do not have any common box 
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cin>>grid[i][j];
        }
    }

    long long sum=0; //letting the intial sum would be 0 
    //now
    for(int i=0;i<n;i++){
        sum+=grid[i][i]; //for left dia
        sum+=grid[i][n-1-i];

    }
    if(n%2==0){
        sum-=grid[n/2][n/2];
    }
cout<<sum;
return 0;
}
#include<bits/stdc++.h>
using namespace std;

//example test case= "aabdddeffb" not re=e


int main(){
  string s;
  cin>>s;
//if only use set then  because wo tree ko follow krta hai hence 
//o (n log n) hence we cnnot use it 
//while the unorderd_set do not use tree thing it uses only bucket thing 
//   unordered_set<char>uset; /
//   for(char c:s){
//     uset.insert(c);
//   }
//   if()
  unordered_map<char,int>freq;
  for(char c:s){
    freq[c]++;
  }
  for(char c:s){
    if(freq[c]==1){
        cout<<c<<" "; 
        break;
    }
    return 0;
  }
}
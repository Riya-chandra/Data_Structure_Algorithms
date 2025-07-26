#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int t;
    cin>>t;
   while(t--){
    int n;
    cin>>n;
     vector<int> a(n);
     for(auto &x:a) cin>>x;
     set<int> prev;
     set<int>total;
     int part_count=0;
     for(int i=0;i<n;i++){
       total.insert(a[i]);
       if(prev.count(a[i])){
        prev.erase(a[i]);
       }
       if(prev.size()==0){
        part_count++;
        prev=total;
       }
     }
     cout<<part_count<<"\n";
   }
   return 0;
}
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        multiset<char>m;
        for(auto x:s){
            m.insert(x);
        }
        for(int i=9;i>=0;i--){
            cout<<*m.lower_bound(i+'0');
            m.erase(m.lower_bound(i+'0'));
        }
        cout<<endl;
    }
}
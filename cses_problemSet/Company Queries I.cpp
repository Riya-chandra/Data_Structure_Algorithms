#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

vector<int> tree[200001];
int up[200001][20];

void binary_lifting(int src,int par){
up[src][0]=par;  //src=first then uska 0 jump up toh parent h hoga 
for(int i=1;i<20;i++){
    if(up[src][i-1]!=-1) //meaning jb tk wo root top p hai jo wo nhi hai toh valid hai 
    
        up[src][i]=up[up[src][i-1]][i-1];
    
    else up[src][i]=-1; // iske upr jump possible nhi hai 
}
for(int child : tree[src]){  //iterate over the next adj
  if(child!=par)
  binary_lifting(child,src);
}
}
int ans_query(int node,int jump_req){
    if(node==-1 || jump_req==0) return node;
    for(int i=19;i>=0;i++){
        if(jump_req>=(1<<i)){
            return ans_query(up[node][i],jump_req-(1<<i));
        }
    }//converting into the binary  src ko tkki min kitne jumps krne hai and then iterative call the next upper 
    //lke 5 level upr ka node chaiye from node 4 then 5 binary 101 which has max power of 2^2 so =4 level upr hogya and now next 
    //up[node][1] (5-4) jump reduced to 1=>001 max powe of 2 is 2^0 hence phele 2^2 hence up(u,2) and now up(p,0) where second one is he power ki ab kitna jump bkki hai
    //up(p,0) 
}
int main(){
    fast_io;
    ll t,n,m,x,i,j,k,q;
    t=1;
    while(t--){
        cin>>n>>q;
        fr(2,n+1){
            cin>>x;
            tree[x].push_back(i); //adj list 
            tree[i].push_back(x);

        }
        binary_lifting(1,-1);//starting from root having no up possible 
        while(q--){
            int node, k;
            cin>> node>>k;
            cout<<ans_query(node,k)<<"\n";
        }
        return 0;
    }
}
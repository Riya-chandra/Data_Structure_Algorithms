#include <vector>
using namespace std;
class Solution {
public:
vector<int> parent;
int find(int x){
    if(parent[x]==x)
    return x;
    return parent[x]=find(parent[x]);
}
void Union(int x,int y){
    parent[y]=x;
}
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int> cost(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            cost[i]=-1;
        }
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            int parentU=find(u);
            int parentV=find(v);
            if(parentU!=parentV){
                Union(parentU,parentV);
                cost[parentU]&=cost[parentV];

            }
            cost[parentU]&=w;

        }
        vector<int> result;
        for(auto &q:query){
            int s=q[0];
            int t=q[1];
   int parentS=find(s);
   int parentT=find(t);
            if(s==t){
                result.push_back(0);
            }else if(parentS!=parentT){
                result.push_back(-1);
            }else{
                result.push_back(cost[parentS]);
            }
        }
        return result;
    }
};
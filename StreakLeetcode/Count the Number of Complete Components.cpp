#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
void dfs(int i,  unordered_map<int,vector<int>>&adj,vector<bool>&Visited,int &nv,int &ne){
Visited[i]=true;
nv++;
ne+=adj[i].size();
for(int &ngbr:adj[i]){
 if(!Visited[ngbr]){
    dfs(ngbr,adj,Visited,nv,ne);
 }
}
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        int result=0;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        vector<bool>Visited(n,false);
        for(int i=0;i<n;i++){
            if(Visited[i]==true)
            continue;
        
        int nv=0;
        int ne=0;
        dfs(i,adj,Visited,nv,ne);
        if((nv*(nv-1))==ne){
         result++;
        }
        }
        return result;
    }
};
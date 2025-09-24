class Solution {
public:
vector<int> parent; //
 int find(int x){
    if(parent[x]!=x) {  //agr cycle hai toh ye zaroor hoga 
        parent[x]=find(parent[x]);  //agr equal nhi h toh parent find krne niklo
    }
    return parent[x];
 }
 bool merge(int x,int y){
    int px=find(x);
    int py=find(y);
    if(px==py) return false;
    parent[py]=px;
    return true;
 }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(!merge(u,v)){  //false 
                return edge;
            }
        }
        return {};
    }
};
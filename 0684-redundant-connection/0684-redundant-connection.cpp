class Solution {
public:
    vector<int> par,rank;
    int find(int u){
        if(u==par[u]) return u;
        return par[u]=find(par[u]);
    }
    bool merge(int u,int v){
        int p1=find(u);
        int p2=find(v);
        if(p1!=p2){
            if(rank[p1]>rank[p2]){
                par[p2]=p1;
                rank[p1]+=rank[p2];
            }
            else{
                par[p1]=p2;
                rank[p2]+=rank[p1];
            }
            return true;
        }
        else{
            return false;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.resize(n+1);
        rank.resize(n+1);
        for(int i=1;i<=n;i++){
            par[i]=i;
            rank[i]=1;
        }
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            bool con=merge(u,v);
            if(con==false) return {u,v};
        }
        return {-1,-1};
    }
};
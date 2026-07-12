class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<list<int>>& adj,vector<int>& parent,vector<int>& disc,vector<int>& lo,int i,int &t,vector<bool>& vis){
        disc[i]=t;
        lo[i]=t;

        for(auto it:adj[i]){
            if(vis[it]==true&&it!=parent[i]){
                lo[i]=min(lo[i],disc[it]);
            }
            else if(!vis[it]){
                vis[it]=true;
                parent[it]=i;
                dfs(adj,parent,disc,lo,it,++t,vis);
                lo[i]=min(lo[i],lo[it]);
                if(lo[it]>disc[i]){
                    ans.push_back({i,it});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>parent(n+1,-1),disc(n+1,-1),lo(n+1,-1);
        vector<bool>vis(n+1,0);
        vector<list<int>>adj(n+1);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        int t=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                vis[i]=true;
                parent[i]=-1;
                dfs(adj,parent,disc,lo,i,++t,vis);
                
            }
        }
        return ans;
    }
};
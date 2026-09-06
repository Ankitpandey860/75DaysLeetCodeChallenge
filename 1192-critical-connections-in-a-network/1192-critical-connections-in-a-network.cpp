class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& dis,vector<int>& lo,vector<int>& par,vector<bool>& vis,int i,vector<list<int>>& adj,int& t){
        dis[i]=t;
        lo[i]=t;
        for(auto it:adj[i]){
            if(vis[it]==true&&it!=par[i]){
                lo[i]=min(lo[i],dis[it]);
            }
            else if(!vis[it]){
                vis[it]=true;
                par[it]=i;
                dfs(dis,lo,par,vis,it,adj,++t);
                lo[i]=min(lo[i],lo[it]);
                if(lo[it]>dis[i]){
                    ans.push_back({i,it});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>par(n+1,-1),dis(n+1,-1),lo(n+1,-1);
        vector<bool>vis(n+1,0);
        vector<list<int>>adj(n+1);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vis[0]=true;
        int t=0;
        dfs(dis,lo,par,vis,0,adj,t);
        
        return ans;
    }
};
class Solution {
public:
    void dfssum(int u, int par, vector<vector<int>>& adj, vector<int>& count, vector<int>& ans) {
        for (int v : adj[u]) {
            if (v == par) continue;
            
            dfssum(v, u, adj, count, ans);
            

            count[u] += count[v];
            ans[u] += ans[v] + count[v];
        }
    }
    void solve(int u,int par,vector<vector<int>>& adj, vector<int>& count, vector<int>& ans,int &n){
        int uptre=n-count[u];
        ans[u]=ans[par]-count[u]+uptre;
        for (int v : adj[u]) {
            if (v == par) continue;
            solve(v,u,adj,count,ans,n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>ans(n),count(n,1),par(n);
        dfssum(0,-1,adj,count,ans);
        for(auto it:adj[0]){
            solve(it,0,adj,count,ans,n);
        }
        return ans;
    }
};
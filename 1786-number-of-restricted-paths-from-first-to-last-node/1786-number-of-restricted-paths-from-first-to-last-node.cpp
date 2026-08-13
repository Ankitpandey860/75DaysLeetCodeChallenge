class Solution {
public:
    const int mod=1e9+7;
    int memo[20005];

    int dfs(int node, int n,  vector<list<pair<int,int>>>& adj, vector<int>& dist) {
        if (node == n) return 1;
        if (memo[node] != -1) return memo[node];

        long long ways = 0;
        for (auto& nbr : adj[node]) {
            int v = nbr.first;
            // Restricted path condition
            if (dist[node] > dist[v]) {
                ways = (ways + dfs(v, n, adj, dist)) % mod;
            }
        }

        return memo[node] = ways;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int>dis(n+1,INT_MAX);
        vector<list<pair<int,int>>>adj(n+1);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        // dis,node
        using p=tuple<int,int>;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,n});
        dis[n]=0;
        while(!pq.empty()){
            auto [wt,curr]=pq.top();
            pq.pop();
            if(dis[curr]<wt) continue;
            for(auto it:adj[curr]){
                int nbr=it.first;
                int nxtwt=wt+it.second;
                if(dis[nbr]>nxtwt){
                    dis[nbr]=nxtwt;
                    pq.push({nxtwt,nbr});
                }
            }
        }
        memset(memo, -1, sizeof(memo));
        return dfs(1, n, adj, dis);
    }
};
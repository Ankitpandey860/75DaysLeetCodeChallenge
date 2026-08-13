class Solution {
public:
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<list<pair<int,int>>>adj(n);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int t=it[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        vector<long long>ways(n);
        ways[0]=1;
        vector<long long>dis(n,LLONG_MAX);
        using p=tuple<long long,int>;
        priority_queue<p,vector<p>,greater<p>>pq;
        dis[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto [time,curr]=pq.top();
            pq.pop();
            if(time>dis[curr]) continue;
            for(auto nbr:adj[curr]){
                long long nt=time+nbr.second;
                int v=nbr.first;
                if(dis[v]>nt){
                    dis[v]=nt;
                    ways[v]=ways[curr];
                    pq.push({nt,v});
                }
                else if(dis[v]==nt){
                    long long currway=(ways[v]+ways[curr])%mod;
                    ways[v]=currway;
                }
            }
        }
        return ways[n-1];
    }
};
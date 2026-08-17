class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<list<pair<int,int>>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int t=it[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        // cost,time,u
        using p=tuple<int,int,int>;
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<vector<int>>dis(n,vector<int>(maxTime+1,INT_MAX));
        pq.push({passingFees[0],0,0});
        dis[0][0]=passingFees[0];
        int ans=INT_MAX;
        while(!pq.empty()){
            auto [cst,t,u]=pq.top();
            pq.pop();
            if(u==n-1){
                ans=min(ans,cst);
            }
            if(dis[u][t]<cst) continue;
            for(auto it:adj[u]){
                int v=it.first;
                int nt=it.second;
                int cst2=passingFees[v];
                if(t+nt<=maxTime&&dis[v][t+nt]>cst2+cst){
                    dis[v][t+nt]=cst2+cst;
                    pq.push({cst2+cst,t+nt,v});
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
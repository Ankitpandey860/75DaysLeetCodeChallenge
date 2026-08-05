class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<list<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        vector<double>dis(n,0);
        using p=tuple<double,int>;
        priority_queue<p>pq;
        pq.push({1.00000,start_node});
        while(!pq.empty()){
            auto [curr,node]=pq.top();
            pq.pop();
            if(node==end_node) return curr;
            if(dis[node]>curr) continue;
            for(auto nbr:adj[node]){
                int v=nbr.first;
                double prob=nbr.second;
                double nxt=curr*prob;
                if(dis[v]<nxt){
                    dis[v]=nxt;
                    pq.push({nxt,v});
                }
            }
        }
        return 0;
    }
};
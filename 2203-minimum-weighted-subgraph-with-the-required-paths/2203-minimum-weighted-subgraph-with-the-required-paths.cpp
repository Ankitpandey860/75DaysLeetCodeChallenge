class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<long long>dis1(n,LLONG_MAX),dis2(n,LLONG_MAX),dis3(n,LLONG_MAX);
        vector<list<pair<int,int>>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        // node,dis
        using p=tuple<long long,int>;
        priority_queue<p,vector<p>,greater<p>>pq1,pq2,pq3;
        pq1.push({0ll,src1});
        dis1[src1]=0;
        while(!pq1.empty()){
            auto [wt,curr]=pq1.top();
            pq1.pop();
            if(dis1[curr]<wt) continue;
            for(auto &it:adj[curr]){
                int v=it.first;
                int w=it.second;
                if(dis1[v]>wt+w){
                    dis1[v]=wt+w;
                    pq1.push({wt+w,v});
                }
            }
        }
        pq2.push({0ll,src2});
        dis2[src2]=0;
        while(!pq2.empty()){
            auto [wt,curr]=pq2.top();
            pq2.pop();
            if(dis2[curr]<wt) continue;
            for(auto &it:adj[curr]){
                int v=it.first;
                long long w=it.second;
                if(dis2[v]>wt+w){
                    dis2[v]=wt+w;
                    pq2.push({wt+w,v});
                }
            }
        }
        adj.clear();
        adj.resize(n);
        for (auto& e : edges) {

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[v].push_back({u, wt});
        }
        pq3.push({0ll,dest});
        dis3[dest]=0;
        while(!pq3.empty()){
            auto [wt,curr]=pq3.top();
            pq3.pop();
            if(dis3[curr]<wt) continue;
            for(auto &it:adj[curr]){
                int v=it.first;
                long long w=it.second;
                if(dis3[v]>wt+w){
                    dis3[v]=wt+w;
                    pq3.push({wt+w,v});
                }
            }
        }

        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            long long oti=dis1[i];
            long long tti=dis2[i];
            long long itd=dis3[i];
            if(oti!=LLONG_MAX&&tti!=LLONG_MAX&&itd!=LLONG_MAX){
                ans=min(ans,oti+tti+itd);
            }
        }
        return ans==LLONG_MAX?-1:ans;
    }
};
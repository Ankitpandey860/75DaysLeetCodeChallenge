class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        //vector<bool>vis(n,false);
        vector<list<pair<int,int>>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int t=it[2];

            adj[u].push_back({v,t});
        }
        vector<vector<long long>>dist(n,vector<long long>(power+1,LLONG_MAX));
        //time,
        using P = pair<long long,pair<long long,int>>;

        priority_queue<P, vector<P>, greater<P>> q;
        priority_queue<pair<int,int>>pq;
        long long mintime=-1;
        int maxpower=-1;
        q.push({0,{power,source}});
        dist[source][power]=0;
        while(!q.empty()){
            long long currt=q.top().first;
            int node=q.top().second.second;
            int plft=q.top().second.first;
            int cst=cost[node];
            q.pop();
            
            if(dist[node][plft]!=currt)
                continue;


            if(node==target){
                if(mintime==-1||mintime>=currt){
                    if(mintime==-1||mintime>currt){
                        mintime=currt;
                        maxpower=plft;
                    }
                    else{
                        maxpower=max(maxpower,plft);
                    }
                }
            }
            if(plft>=cst){

                for(auto it:adj[node]){
                    int v=it.first;
                    long long time=it.second;
                    long long nt = currt + time;
                    int np = plft - cst;

                    if(nt < dist[v][np]){
                        dist[v][np] = nt;
                        q.push({nt,{np,v}});
                    }
                }
            }
            
        }/*
        int maxpower=-1;
        pq.push({power,source});
        vector<long long>disp(n,LLONG_MIN);
        while(!pq.empty()){
            int node=pq.top().second;
            int plft=pq.top().first;
            pq.pop();
            int cst=cost[node];
            if(node==target){
                maxpower=plft;
                break;
            }
            if(plft<=disp[node]){
                continue;
            }
            disp[node]=plft;
            if(plft>=cst){

                for(auto it:adj[node]){
                    int v=it.first;
                    
                    int np = plft - cst;

                    if(np > disp[v]){
                        pq.push({np,v});
                    }
                }
            }
        }*/
        return {mintime,maxpower};
    }
};
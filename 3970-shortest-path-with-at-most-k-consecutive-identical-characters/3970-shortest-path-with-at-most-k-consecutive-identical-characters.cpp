class Solution {
public:
    const int INF = 1e9;

    
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<list<pair<int,int>>>adj(n);
        vector<vector<int>> dist(
            n,
            vector<int>(k, INF)
        );
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
        }
        using Element = pair<int,pair<int,pair<int,char>>>;
        priority_queue<Element,vector<Element>,greater<Element>> pq;

        pq.push({0,{k-1,{0,labels[0]}}});
        dist[0][k-1]= 0;
        while(!pq.empty()){
            int node=pq.top().second.second.first;
            int wt=pq.top().first;
            int allowed=pq.top().second.first;
            char ch=pq.top().second.second.second;

            pq.pop();
            if (wt > dist[node][allowed])
                    continue;
       

            if(node==n-1) return wt;
            for(auto& it:adj[node]){
                int nbr=it.first;
                int wt2=it.second;
                char ch2=labels[nbr];
                
                if(ch2==ch){
                    if (allowed > 0 &&
                        wt + wt2 < dist[nbr][allowed-1]) {

                        dist[nbr][allowed-1]= wt + wt2;

                        pq.push({wt+wt2,{allowed-1,{nbr,ch2}}});
                    }

                    
                }else{
 
                    if (wt + wt2 < dist[nbr][k-1]) {

                        dist[nbr][k-1]= wt + wt2;

                        pq.push({wt+wt2,{k-1,{nbr,ch2}}});
                    }
                    
                }
            }
        }
        return -1;
    }
};
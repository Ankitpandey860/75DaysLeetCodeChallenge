class Solution {
public:
    void bfs(vector<list<int>>& adj,int node,vector<bool>& vis,int& loop){
        /*if (connections.size() < n - 1) {
            return -1;
        }*/

        queue<pair<int,int>>q;
        q.push({node,-1});
        vis[node]=true;
        while(!q.empty()){
            int curr=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto nbr:adj[curr]){
                if(nbr!=par){
                    if(!vis[nbr]){
                        vis[nbr]=true;
                        q.push({nbr,curr});
                    }else{
                        loop++;
                    }
                }
                
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<list<int>>adj(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int loop=0;
        int cnt=0;
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                bfs(adj,i,vis,loop);
            }
        }
        cnt--;
        loop/=2;
        return cnt<=loop?cnt:-1;
    }
};
class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<list<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>dis(3,vector<int>(n,-1));
        vector<bool>vis(n);
        queue<pair<int,int>>q;
        q.push({x,0});
        vis[x]=true;
        dis[0][x] = 0;
        dis[1][y] = 0;
        dis[2][z] = 0;
        while(!q.empty()){
            int node=q.front().first;
            int step=q.front().second;
            q.pop();
            for(auto nbr:adj[node]){
                if(!vis[nbr]){
                    q.push({nbr,step+1});
                    vis[nbr]=true;
                    dis[0][nbr]=step+1;
                }
            }
        }
        fill(vis.begin(), vis.end(), false);
        vis[y]=true;
        q.push({y,0});
        while(!q.empty()){
            int node=q.front().first;
            int step=q.front().second;
            q.pop();
            for(auto nbr:adj[node]){
                if(!vis[nbr]){
                    q.push({nbr,step+1});
                    vis[nbr]=true;
                    dis[1][nbr]=step+1;
                }
            }
        }
        fill(vis.begin(), vis.end(), false);
        vis[z]=true;
        q.push({z,0});
        while(!q.empty()){
            int node=q.front().first;
            int step=q.front().second;
            q.pop();
            for(auto nbr:adj[node]){
                if(!vis[nbr]){
                    q.push({nbr,step+1});
                    vis[nbr]=true;
                    dis[2][nbr]=step+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int dx=max(dis[0][i],max(dis[1][i],dis[2][i]));
            int dy=min(dis[0][i],min(dis[1][i],dis[2][i]));
            int dz=dis[0][i]+dis[1][i]+dis[2][i]-(dx+dy);
            if((1ll*dx*dx)==(1ll*dy*dy+1ll*dz*dz)) ans++;
        }
        return ans;
    }
};
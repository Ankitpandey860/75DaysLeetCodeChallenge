class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pr) {
        vector<bool>vis(n,0);
        vector<int>indeg(n,0),ans;
        vector<list<int>>adj(n);
        for(auto it:pr){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
                
            }
        }
        queue<int>q;
        int visi=0;
        for(int i=0;i<n;i++){
            if(!indeg[i]){
                q.push(i);
                ans.push_back(i);
                vis[i]=true;
                visi++;
            }
        }
        if(q.empty()) return {};
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                    vis[it]=true;
                    ans.push_back(it);
                    visi++;
                }
            }
        }
        if(visi!=n) return {};
        for(auto it:vis){
            if(it==false) return {};
        }
        return ans;
    }
};
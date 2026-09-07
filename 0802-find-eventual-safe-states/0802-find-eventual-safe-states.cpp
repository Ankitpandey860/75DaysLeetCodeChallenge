class Solution {
public:
    bool solve(int i,vector<list<int>>& adj,vector<int>& dp,vector<bool>& vis){
        if(adj[i].empty()) return dp[i]=1;
        if(dp[i]!=-1) return dp[i];
        bool poss=true;
        for(auto it:adj[i]){
            
            if(!vis[it]){
                vis[it]=true;
                bool curr=solve(it,adj,dp,vis);
                if(!curr) return poss=false;
            }
            else{
                if(dp[it]!=1)
                    poss=false;
            }
            
        }
        return dp[i]=poss;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<list<int>>adj(n);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<int>dp(n,-1);
        
        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            if(!vis[i])
                solve(i,adj,dp,vis);
        }
        vector<int> ans;
        
        for(int i=0;i<n;i++){
           if(dp[i]==1)
                ans.push_back(i);
        }
        return ans;
    }
};
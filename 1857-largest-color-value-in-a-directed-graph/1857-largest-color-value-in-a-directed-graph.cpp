class Solution {
public:
    int dfs(vector<list<int>>& adj,int curr,int req,string& colors,vector<vector<int>>& dp){
        int temp=colors[curr]-'a';
        int ans=0;
        if(dp[curr][req]!=-1) return dp[curr][req];
        for(auto it:adj[curr]){
            ans=max(ans,dfs(adj,it,req,colors,dp));
        }
        if(temp==req) ans++;
        return dp[curr][req]=ans;
    }
    bool detectcycle(vector<int>& prefix, vector<list<int>>& adj, int n) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (prefix[i] == 0) q.push(i);
        }

        int visited = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited++;

            for (int next : adj[curr]) {
                prefix[next]--;
                if (prefix[next] == 0) {
                    q.push(next);
                }
            }
        }

        return visited != n;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<list<int>>adj(n);
        vector<int>prefix(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            prefix[v]++;
        }
        bool temp=detectcycle(prefix,adj,n);
        if(temp) return -1;
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(26,-1));
        for (int i = 0; i < n; i++) {
            if (prefix[i] == 0) { // Start DFS from all components/roots
                for (int c = 0; c < 26; c++) {
                    ans = max(ans, dfs(adj, i, c, colors, dp));
                }
            }
        }
        return ans;
    }
};
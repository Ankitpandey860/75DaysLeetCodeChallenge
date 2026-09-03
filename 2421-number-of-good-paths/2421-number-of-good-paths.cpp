class Solution {
public:
    int find(vector<int>& par,int a){
        if(a==par[a]) return a;
        return par[a]=find(par,par[a]);
    }
    void uni(vector<int>& par,vector<int>& rank,int &a,int& b){
        int pa=find(par,a);
        int pb=find(par,b);
        if(pa==pb) return;
        if(rank[pa]>rank[pb]){
            rank[pa]+=rank[pb];
            par[pb]=pa;
        }else{
            rank[pb]+=rank[pa];
            par[pa]=pb;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        int m=edges.size();
        map<int,list<int>>valtonode;
        vector<int>rank(n,1),par(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        int ans=0;
        // value to node map 
        for(int i=0;i<vals.size();i++){
            valtonode[vals[i]].push_back(i);
        }

        // adjecency list
        unordered_map<int,list<int>>adj;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // smallest value pakda abb wohh jis jis node ki value h unke edges check kiye joo judd skte h jod diye
        for(auto it:valtonode){
            int val=it.first;
            for(auto u:it.second){
                for(auto v:adj[u]){
                    if(vals[v]<=val){
                        uni(par,rank,u,v);
                    }
                }
            }
            // hrr component me iss value ka count 
            unordered_map<int,int>mp;
            for(auto u:it.second){
                int pu=find(par,u);
                mp[pu]++;
            }
            for(auto it:mp){
                int cnt=it.second;
                cnt--;
                int curr =(1ll*cnt*(cnt+1))/2;
                ans+=curr;
            }
        }
        return ans+n;
        
    }
};
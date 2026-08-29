class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[2]<b[2];
    }
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<vector<int>> temp=queries;
        sort(temp.begin(),temp.end(),cmp);
        sort(edgeList.begin(),edgeList.end(),cmp);
        vector<list<pair<int,int>>>adj(n);
        vector<int>par(n),rank(n);
        map<vector<int>,bool>mp;
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=1;
        }
        /*for(auto it:edgeList){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back(v);
        }*/
        int i=0,j=0;
        while(j<temp.size()){
            int lim=temp[j][2];
            while(i<edgeList.size()&&edgeList[i][2]<lim){
                int u=edgeList[i][0];
                int v=edgeList[i][1];
                uni(par,rank,u,v);
                i++;
            }
            int u=temp[j][0];
            int v=temp[j][1];
            int pa=find(par,u);
            int pb=find(par,v);
            if(pa==pb){
                mp[temp[j]]=true;
            }
            j++;
        }
        int m=temp.size();
        vector<bool>ans(m,false);
        for(int i=0;i<m;i++){
            if(mp.find(queries[i])!=mp.end()){
                ans[i]=true;
            }
        }
        return ans;
    }
};
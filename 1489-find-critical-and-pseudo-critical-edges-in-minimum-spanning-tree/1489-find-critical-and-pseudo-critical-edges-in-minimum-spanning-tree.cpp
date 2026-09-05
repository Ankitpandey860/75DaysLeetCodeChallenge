class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[2]<b[2];
    }
    int find(vector<int>& par,int a){
        if(a==par[a]) return a;
        return par[a]=find(par,par[a]);
    }
    void uni(vector<int>& rank,vector<int>& par,int &a,int& b){
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
    void reset(vector<int>& rank,vector<int>& par){
        for(int i=0;i<rank.size();i++){
            par[i]=i;
            rank[i]=1;
        }
    }
    int mst(vector<int>& rank,vector<int>& par,int add,int remove,vector<vector<int>>& edges){
        int wt=0;
        int cnt=0;
        int n=rank.size();
        if(add!=-1){
            uni(rank,par,edges[add][0],edges[add][1]);
            wt+=edges[add][2];
            cnt++;
        }
        for(int i=0;i<edges.size();i++){
            if(i==remove) continue;
            int u=edges[i][0];
            int v=edges[i][1];
            int pu=find(par,u);
            int pv=find(par,v);
            if(pu!=pv){
                uni(rank,par,u,v);
                wt+=edges[i][2];
                cnt++;
            }
        }
        reset(rank,par);
        return cnt == n - 1 ? wt : INT_MAX;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),cmp);
        vector<vector<int>>ans(2);
        vector<int>rank(n),par(n);
        reset(rank,par);
        int mincst=mst(rank,par,-1,-1,edges);
        for(int i=0;i<edges.size();i++){
            // add
            int cstadd=mst(rank,par,i,-1,edges);

            // remove
            int cstremove =mst(rank,par,-1,i,edges);
            if(cstremove>mincst){
                ans[0].push_back(edges[i][3]);
            }
            else if(cstadd==mincst){
                ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int calc(vector<int>& a,vector<int>& b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    using p=tuple<int,int,int>;
    int find(vector<int>& par,int a){
        if(a==par[a]) return a;
        return par[a]=find(par,par[a]);
    }
    void reset(vector<int>& rank,vector<int>& par){
        for(int i=0;i<rank.size();i++){
            par[i]=i;
            rank[i]=1;
        }
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
    int mst(priority_queue<p,vector<p>,greater<p>>& pq,int n,vector<int>& rank,vector<int>& par){
        int cst=0;
        while(!pq.empty()){
            auto [wt,u,v]=pq.top();
            pq.pop();
            int pu=find(par,u);
            int pv=find(par,v);
            if(pu!=pv){
                uni(rank,par,u,v);
                cst+=wt;
            }
        }
        return cst;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt=calc(points[i],points[j]);
                pq.push({wt,i,j});
            }
        }
        vector<int>rank(n),par(n);
        reset(rank,par);
        return mst(pq,n,rank,par);
    }
};
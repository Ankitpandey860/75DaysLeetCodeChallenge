class Solution {
public:
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int mask=pow(2,n)-1;

        //step,msk,node>
        using p=tuple<int,int,int>;
        priority_queue<p,vector<p>,greater<p>>pq;
        int ans=INT_MAX;
        vector<vector<bool>> vis(1 << n, vector<bool>(n, false));
        for(int i=0;i<n;i++){
            int msk=1<<i;
            vis[msk][i]=true;
            pq.push({0,msk,i});
            
        }
        while(!pq.empty()){
                auto [step,msk,node]=pq.top();
                pq.pop();
                if(msk==mask){
                    ans=min(ans,step);
                    break;
                }
                for(auto nbr:graph[node]){
                    int newmsk=msk|(1<<nbr);
                    if(!vis[newmsk][nbr]){
                        vis[newmsk][nbr]=true;
                        pq.push({step+1,newmsk,nbr});
                    }
                }
            }
        return ans;
    }
};
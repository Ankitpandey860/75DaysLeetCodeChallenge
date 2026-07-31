class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        int n=routes.size();
        unordered_map<int,vector<int>>rtb,btr;
        for(int i=0;i<n;i++){
            for(auto it:routes[i]){
                rtb[i].push_back(it);
                btr[it].push_back(i);
            }
        }
        // step bus
        using p=tuple<int,int>;
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<int>vis(n,false);
        for(auto it:btr[source]){
            vis[it]=true;
            for(auto it2:rtb[it]){
                pq.push({1,it2});
            }
        }
        while(!pq.empty()){
            auto [step,bus]=pq.top();
            pq.pop();
            if(bus==target) return step;
            for(auto rots:btr[bus]){
                if(vis[rots]) continue;
                vis[rots]=true;
                for(auto bus2:rtb[rots]){
                    pq.push({step+1,bus2});
                }
            }
        }
        return -1;
    }
};
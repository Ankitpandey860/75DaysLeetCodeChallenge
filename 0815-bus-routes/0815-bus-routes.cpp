class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n=routes.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<routes.size();i++){
            for(auto it:routes[i]){
                mp[it].push_back(i);
            }
        }
        unordered_set<int>vis2;
        vector<int>vis1(n,false);
        queue<pair<int,int>>q;
        q.push({source,0});
        vis2.insert(source);
        while(!q.empty()){
            int curr=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(curr==target) return dis;
            for(auto it:mp[curr]){
                if(!vis1[it]){
                    for(auto it2:routes[it]){
                        if(vis2.count(it2)==0){
                            q.push({it2,dis+1});
                            vis2.insert(it2);
                        }
                    }
                    vis1[it]=true;
                }
            }
        }
        return -1;
    }
};
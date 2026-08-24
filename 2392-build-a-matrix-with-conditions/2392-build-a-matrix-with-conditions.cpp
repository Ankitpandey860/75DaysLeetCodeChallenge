class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<list<int>>ver(k+1),hor(k+1);
        vector<int>row,col,indegv(k+1,0),indegh(k+1,0);
        for(auto it:rowConditions){
            int u=it[0];
            int v=it[1];
            ver[u].push_back(v);
            indegv[v]++;
        }
        for(auto it:colConditions){
            int u=it[0];
            int v=it[1];
            hor[u].push_back(v);
            indegh[v]++;
        }
        queue<int>q;
        for(int i=1;i<=k;i++){
            if(indegv[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            row.push_back(curr);
            for(auto it:ver[curr]){
                indegv[it]--;
                if(indegv[it]==0){
                    q.push(it);
                }
            }
        }
        if(row.size()!=k) return {};
        //q.clear();
        for(int i=1;i<=k;i++){
            if(indegh[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            col.push_back(curr);
            for(auto it:hor[curr]){
                indegh[it]--;
                if(indegh[it]==0){
                    q.push(it);
                }
            }
        }
        if(col.size()!=k) return {};
        unordered_map<int,int>up,lft;
        for(int i=0;i<k;i++){
            up[row[i]]=i;
            lft[col[i]]=i;
        }
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            int r=up[i];
            int c=lft[i];
            ans[r][c]=i;
        }
        return ans;
    }
};
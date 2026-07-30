class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int limit) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        using p = tuple<int, int, int, int>;//steps,k,r,c
        priority_queue<p,vector<p>,greater<p>>pq;
        if(grid[0][0]==0){
            pq.push({0,0,0,0});
        }
        int arr[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vis[0][0]=0;
        while(!pq.empty()){
            auto [steps,k,r,c]=pq.top();
            pq.pop();
            if(r==n-1&&c==m-1) return steps;
            for(auto it:arr){
                int nr=r+it[0];
                int nc=c+it[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if(vis[nr][nc]==-1||vis[nr][nc]>k){
                        if(grid[nr][nc]==0){
                            vis[nr][nc]=k;
                            pq.push({steps+1,k,nr,nc});
                        }else{
                            if(k<limit){
                                vis[nr][nc]=k+1;
                                pq.push({steps+1,k+1,nr,nc});
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};
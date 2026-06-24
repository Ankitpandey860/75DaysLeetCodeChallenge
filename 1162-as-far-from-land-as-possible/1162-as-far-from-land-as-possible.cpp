class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        int arr[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({0,{i,j}});
                    vis[i][j]=true;
                }
            }
        }
        int lst=-1;
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            int w=q.front().first;
            q.pop();
            if(grid[r][c]==0){
                lst=w;
            }
            for(auto it:arr){
                int nr=r+it[0];
                int nc=c+it[1];
                if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()&&!vis[nr][nc]){
                    q.push({w+1,{nr,nc}});
                    vis[nr][nc]=true;
                }
            }
        }
        return lst;
    }
};
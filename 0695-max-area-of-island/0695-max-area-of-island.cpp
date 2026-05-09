class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int i,int j){
        int ans=0;
        int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        for(auto it:dir){
            int nr=i+it[0];
            int nc=j+it[1];
            if(nr>=0&&nr<grid.size()&&nc>=0&&nc<grid[0].size()&&grid[nr][nc]==1&&!vis[nr][nc]){
                ans++;
                vis[nr][nc]=true;
                ans+=dfs(grid,vis,nr,nc);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j]&&grid[i][j]==1){
                    vis[i][j]=true;
                    ans=max(ans,1+dfs(grid,vis,i,j));
                }
            }
        }
        return ans;
    }
};
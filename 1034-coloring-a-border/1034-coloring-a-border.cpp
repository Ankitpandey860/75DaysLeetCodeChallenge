class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int colr=grid[row][col];
        queue<pair<int,int>>q;
        q.push({row,col});
        vector<vector<int>> ans=grid;
        int arr[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        //vector<vector<int>> grid2=grid;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            
            q.pop();
            int cnt=0;
            for(auto it:arr){
                int nr=r+it[0];
                int nc=c+it[1];
                if(nr>=0&&nr<grid.size()&&nc>=0&&nc<grid[0].size()&&grid[nr][nc]==colr){
                    if(!vis[nr][nc])
                        q.push({nr,nc});
                    vis[nr][nc]=true;
                    cnt++;
                }
            }
            if(cnt<4){
                ans[r][c]=color;
            }
            //vis[r][c]=true;
        }
        return ans;
    }
};
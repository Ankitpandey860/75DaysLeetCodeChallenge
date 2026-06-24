class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {


        int n=grid.size();
        int m=grid[0].size();
        bool found=false;
        queue<pair<int,int>>q;
        queue<pair<int,pair<int,int>>>q2;
        vector<vector<bool>>vis(n,vector<bool>(m,false));



        for(int i=0;i<n&&!found;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=true;
                    found=true;
                    break;
                }
            }
        }
        int arr[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q2.push({0,{r,c}});
            q.pop();
            for(auto it:arr){
                int nr=r+it[0];
                int nc=c+it[1];
                if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()&&!vis[nr][nc]&&grid[nr][nc]==1){
                    q.push({nr,nc});
                    vis[nr][nc]=true;
                }
            }
        }

        while(!q2.empty()){
            int r=q2.front().second.first;
            int c=q2.front().second.second;
            int w=q2.front().first;
            q2.pop();
            for(auto it:arr){
                int nr=r+it[0];
                int nc=c+it[1];
                if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()&&!vis[nr][nc]){
                    if(grid[nr][nc]==1) return w;
                    q2.push({w+1,{nr,nc}});
                    vis[nr][nc]=true;
                }
            }
        }
        return -1;
    }
};
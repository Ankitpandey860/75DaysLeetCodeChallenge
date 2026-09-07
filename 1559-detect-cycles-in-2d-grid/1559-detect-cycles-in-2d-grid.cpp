class Solution {
public:
    int arr[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
    bool valid(int i,int j,int& n,int &m){
        if(i<0||j<0||i>=n||j>=m) return false;
        return true;
    }
    bool dfs(vector<vector<char>>& grid,int i,int j,int pi,int pj,vector<vector<bool>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        for(auto it:arr){
            int ni=i+it[0];
            int nj=j+it[1];
            if(valid(ni,nj,n,m)&&(grid[i][j]==grid[ni][nj])&&(pi!=ni||pj!=nj)){
                if(vis[ni][nj]) return true;
                vis[ni][nj]=true;
                bool curr=dfs(grid,ni,nj,i,j,vis);
                if(curr) return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    vis[i][j]=true;
                    bool curr=dfs(grid,i,j,-1,-1,vis);
                    if(curr) return true;
                }
            }
        }
        return false;

    }
};
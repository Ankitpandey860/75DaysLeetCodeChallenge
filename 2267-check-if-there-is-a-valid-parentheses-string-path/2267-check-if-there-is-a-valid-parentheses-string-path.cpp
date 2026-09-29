class Solution {
public:
    bool solve(vector<vector<char>>& grid,int i,int j,int cnt,int& n,int& m,vector<vector<vector<int>>>& dp){
        if(i==n-1&&j==m-1){
            return cnt==0;
        }
        if(cnt<0) return false;
        if(dp[i][j][cnt]!=-1) return dp[i][j][cnt];
        // down
        bool down=false,right=false;
        if(i+1<n){
            if(grid[i+1][j]=='('){
                down=solve(grid,i+1,j,cnt+1,n,m,dp);
            }
            else{
                down=solve(grid,i+1,j,cnt-1,n,m,dp);
            }
        }
        if(j+1<m){
            if(grid[i][j+1]=='('){
                right=solve(grid,i,j+1,cnt+1,n,m,dp);
            }
            else{
                right=solve(grid,i,j+1,cnt-1,n,m,dp);
            }
        }
        return dp[i][j][cnt]=down|right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==')'||grid[n-1][m-1]=='(') return false;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(5001,-1)));
        return solve(grid,0,0,1,n,m,dp);
    }
};
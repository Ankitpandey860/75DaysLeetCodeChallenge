class Solution {
public:
    int solve(vector<vector<int>>& grid, int &limit,int i,int prev,vector<vector<int>>& dp){
        if(i >= grid[0].size()) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev]; 
        int exc=solve(grid,limit,i+1,prev,dp);
        int inc=0;
        for(int r=0;r<grid.size();r++){
            if(abs(grid[r][i]-grid[r][prev])>limit) return dp[i][prev]=exc;
            
        }
        inc=max(inc,1+solve(grid,limit,i+1,i,dp));
        return dp[i][prev]=max(inc,exc);
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int ans=0;
        int n=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<grid[0].size();i++){
            ans=max(ans,1+solve(grid,limit,i+1,i,dp));
        }
        return ans;
    }
};
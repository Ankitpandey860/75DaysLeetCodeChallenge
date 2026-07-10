class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i>=grid.size()||j>=grid[0].size()) return 0;
        if(grid[i][j]==1) return 0;
        if(i==grid.size()-1&&j==grid[0].size()-1) return 1;
        int right=solve(grid,i,j+1);
        int down=solve(grid,i+1,j);
        return right+down;
    }

    int memo(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i>=grid.size()||j>=grid[0].size()) return 0;
        if(grid[i][j]==1) return dp[i][j]=0;
        if(i==grid.size()-1&&j==grid[0].size()-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=memo(grid,i,j+1,dp);
        int down=memo(grid,i+1,j,dp);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
       // return solve(grid,0,0);



       //memoisation
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
        return memo(grid,0,0,dp);
    }
};
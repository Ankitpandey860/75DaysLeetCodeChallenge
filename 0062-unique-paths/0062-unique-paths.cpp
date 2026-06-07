class Solution {
public:
    int solve(int i,int j,int m,int n){
        if(i==m-1&&j==n-1){
            return 1;
        }
        if(i==m||j==n){
            return 0;
        }
        int down=solve(i+1,j,m,n);
        int up=solve(i,j+1,m,n);
        return up+down;
    }
    int memo(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i==m-1&&j==n-1){
            return 1;
        }
        if(i==m||j==n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=memo(i+1,j,m,n,dp);
        int up=memo(i,j+1,m,n,dp);
        return dp[i][j]=up+down;
    }
    int uniquePaths(int m, int n) {
        //return solve(0,0,m,n);
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return memo(0,0,m,n,dp);
    }
};